#include <bits/stdc++.h>
using namespace std;

// For type 2 queries:
// Root not in subtree of LCA --> subtree of LCA
// Root on path from u, v --> entire tree
// Everywhere else --> everything except subtree stemming from (u, v) path containing root

using ll = long long;

const int N = 1e5 + 69, L = 19;
int n, q, rt = 1, a[N];
vector<int> adj[N];

// Lazy Segtree {{{
template<class T> struct LZ_ST {
    static constexpr T ID = 0, LZ_ID = 0; // or whatever ID
    inline T comb(T a, T b) { return a + b; } // or whatever function

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
        if (l != r) { // might have to change
            int m = l + r >> 1;
            t[v * 2] += lz[v] * (m - l + 1);
            t[v * 2 + 1] += lz[v] * (r - m);
            lz[v * 2] += lz[v];
            lz[v * 2 + 1] += lz[v];
        }
        lz[v] = LZ_ID;
    }
    void upd(int ql, int qr, T x, int l, int r, int v) {
        if (qr < l || ql > r) return;
        if (l >= ql && r <= qr) // might have to change
            t[v] += x * (r - l + 1), lz[v] += x;
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

LZ_ST<ll> st;

// Tree stuff {{{
int tt, tin[N], tout[N], dep[N], lift[N][L];
void dfs(int v = 1, int p = 0, int d = 0) {
    tin[v] = tt++, dep[v] = d;

    lift[v][0] = p;
    for (int i = 1; i < L; ++i)
        lift[v][i] = lift[lift[v][i - 1]][i - 1];

    for (int u : adj[v])
        if (u != p)
            dfs(u, v, d + 1);

    tout[v] = tt - 1;
}
bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
bool on_path(int v, int l, int x) {
    return (is_anc(l, x) && is_anc(x, v));
}
int jump(int v, int k) {
    for (int i = 0; i < L; ++i)
        if (k & (1 << i))
            v = lift[v][i];
    return v;
}
int lca(int u, int v) {
    if (is_anc(u, v))
        return u;
    if (is_anc(v, u))
        return v;

    for (int i = L - 1; ~i; --i)
        if (lift[v][i] && !is_anc(lift[v][i], u))
            v = lift[v][i];

    return lift[v][0];
}
// }}}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    st.init(n);
    for (int i = 1; i <= n; ++i)
        st.upd(tin[i], tin[i], a[i]);

    while (q--) {
        int c;
        cin >> c;

        if (c == 1)
            cin >> rt;
        else if (c == 2) {
            int u, v, l; ll x;
            cin >> u >> v >> x, l = lca(u, v);

            if (!is_anc(l, rt))
                st.upd(tin[l], tout[l], x);
            else if (on_path(u, l, rt) || on_path(v, l, rt))
                st.upd(0, n - 1, x);
            else {
                int lu = lca(u, rt), lv = lca(v, rt);
                if (dep[lu] < dep[lv])
                    swap(lu, lv);

                int s = jump(rt, dep[rt] - dep[lu] - 1);
                st.upd(0, n - 1, x);
                st.upd(tin[s], tout[s], -x);
            }
        } else {
            int v;
            cin >> v;

            if (rt == v)
                cout << st.query(0, n - 1) << '\n';
            else if (!is_anc(v, rt))
                cout << st.query(tin[v], tout[v]) << '\n';
            else {
                int s = jump(rt, dep[rt] - dep[v] - 1);
                cout << st.query(0, n - 1) - st.query(tin[s], tout[s]) << '\n';
            }
        }
    }
}

