#include <bits/stdc++.h>
using namespace std;

// Lazy Segtree {{{
template<class T> struct LZ_ST {
    static constexpr T ID = 0, LZ_ID = -1; // or whatever ID
    inline T comb(T a, T b) { return max(a, b); } // or whatever function

    int sz;
    vector<T> t, lz;

    void init(int _sz, T val = ID) {
        sz = _sz;
        t.assign(sz * 4, val);
        lz.assign(sz * 4, LZ_ID);
    }
    void init(vector<T> &a) {
        sz = a.size();
        t.resize(sz * 4);
        lz.assign(sz * 4, LZ_ID);

        build(0, sz - 1, 1, a);
    }
    void build(int l, int r, int v, vector<T> &a) {
        if (l == r)
            t[v] = a[l];
        else {
            int m = l + r >> 1;
            build(l, m, v * 2, a);
            build(m + 1, r, v * 2 + 1, a);
            t[v] = comb(t[v * 2], t[v * 2 + 1]);
        }
    }
    inline void push(int l, int r, int v) {
        if (~lz[v] && l != r) { // might have to change
            t[v * 2] =  t[v * 2 + 1] = lz[v];
            lz[v * 2] = lz[v * 2 + 1] = lz[v];
        }
        lz[v] = LZ_ID;
    }
    void upd(int ql, int qr, T x, int l, int r, int v) {
        if (qr < l || ql > r) return;
        if (l >= ql && r <= qr) // might have to change
            t[v] = lz[v] = x;
        else {
            push(l, r, v);
            int m = l + r >> 1;
            upd(ql, qr, x, l, m, v * 2);
            upd(ql, qr, x, m + 1, r, v * 2 + 1);
            t[v] = comb(t[v * 2], t[v * 2 + 1]);
        }
    }
    void upd(int ql, int qr, T x) {
        upd(ql, qr, x, 0, sz - 1, 1);
    }
    T query(int ql, int qr, int l, int r, int v) {
        if (qr < l || ql > r) return ID;
        if (l >= ql && r <= qr) return t[v];
        push(l, r, v);
        int m = l + r >> 1;
        return comb(query(ql, qr, l, m, v * 2), query(ql, qr, m + 1, r, v * 2 + 1));
    }
    T query(int ql, int qr) {
        return query(ql, qr, 0, sz - 1, 1);
    }
};
// }}}

// HLD {{{
// to be used with lazy segtree, assumes 0-indexed
template<class T, bool EDGES = 0> struct HLD {
    int sz, tt = 0;
    vector<vector<int>> adj;
    vector<int> par, siz, dep, head, pos, tour;
    LZ_ST<T> tree;

    HLD(vector<vector<int>> _adj, vector<T> vals = {}) : sz(_adj.size()), adj(_adj) {
        par.assign(sz, -1), siz.assign(sz, 1);
        dep.resize(sz), head.resize(sz), pos.resize(sz);
        tour.reserve(sz);

        dfs_sz(0); dfs_decomp(0);

        if (vals.empty())
            tree.init(sz);
        else {
            vector<T> ret(sz);
            for (int i = 0; i < sz; ++i)
                ret[i] = vals[tour[i]];
            tree.init(ret);
        }
    }

    void dfs_sz(int v) {
        if (~par[v])
            adj[v].erase(find(adj[v].begin(), adj[v].end(), par[v]));

        for (int &u : adj[v]) {
            par[u] = v, dep[u] = dep[v] + 1;
            dfs_sz(u);

            siz[v] += siz[u];
            if (siz[u] > siz[adj[v][0]])
                swap(u, adj[v][0]);
        }
    }
    void dfs_decomp(int v) {
        pos[v] = tt++;
        tour.push_back(v);

        for (int u : adj[v]) {
            head[u] = (u == adj[v][0] ? head[v] : u);
            dfs_decomp(u);
        }
    }
    template<class B> void op_path(int u, int v, B op) {
        for (; head[u] != head[v]; v = par[head[v]]) {
            if (dep[head[u]] > dep[head[v]]) swap(u, v);
            op(pos[head[v]], pos[v]);
        }
        if (dep[u] > dep[v]) swap(u, v);
        op(pos[u] + EDGES, pos[v]);
    }
    void upd_path(int u, int v, T x) {
        op_path(u, v, [&](int l, int r) { tree.upd(l, r, x); });
    }
    T query_path(int u, int v) {
        T ret = tree.ID;
        op_path(u, v, [&](int l, int r) { ret = tree.comb(ret, tree.query(l, r)); });
        return ret;
    }
    void upd_subtree(int v, T x) {
        tree.upd(pos[v] + EDGES, pos[v] + siz[v], x);
    }
    T query_subtree(int v) {
        return tree.query(pos[v] + EDGES, pos[v] + siz[v]);
    }
};
// }}}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n), col(n);
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        col[c - 1].push_back(i);
    }

    HLD<int, true> h(adj);
    for (int i = 0; i < n; ++i) {
        auto &v = col[i];
        for (int j = 1; j < v.size(); ++j)
            h.upd_path(v[j - 1], v[j], 1);
    }

    int ans = n - 1;
    for (int i = 1; i < n; ++i)
        ans -= h.query_path(i, h.par[i]);

    cout << ans << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

