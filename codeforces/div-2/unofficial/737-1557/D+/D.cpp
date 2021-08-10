#include <bits/stdc++.h>
using namespace std;

// Lazy Segtree {{{
template<class T> struct LZ_ST {
    const T ID = {0, -1}, LZ_ID = {-1, -1}; // or whatever ID
    inline T comb(T a, T b) { return max(a, b); } // or whatever function

    int sz;
    vector<T> t, lz;

    void init(int _sz, T val = {0, -1}) {
        sz = _sz;
        t.resize(sz * 4, val);
        lz.resize(sz * 4, LZ_ID);
    }
    void init(vector<T> &a) {
        sz = a.size();
        t.resize(sz * 4);
        lz.resize(sz * 4, LZ_ID);

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
        if (l != r && ~lz[v][0]) { // might have to change
            t[v * 2] = t[v * 2 + 1] = lz[v];
            lz[v * 2] = lz[v * 2 + 1] = lz[v];
        }
        lz[v] = LZ_ID;
    }
    void upd(int ql, int qr, T x, int l, int r, int v) {
        if (qr < l || ql > r)
            return;
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
        if (qr < l || ql > r)
            return ID;
        if (l >= ql && r <= qr)
            return t[v];
        push(l, r, v);
        int m = l + r >> 1;
        return comb(query(ql, qr, l, m, v * 2), query(ql, qr, m + 1, r, v * 2 + 1));
    }
    T query(int ql, int qr) {
        return query(ql, qr, 0, sz - 1, 1);
    }
};
// }}}

const int N = 3e5 + 69;
int n, m, par[N];
vector<array<int, 2>> segs[N];
map<int, int> mp;

int main() {
    memset(par, -1, sizeof(par));

    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;


    while (m--) {
        int i, l, r;
        cin >> i >> l >> r;

        mp[l], mp[r];
        segs[i - 1].push_back({l, r});
    }

    int cmp = 1;
    for (auto &[x, v] : mp)
        v = cmp++;

    LZ_ST<array<int, 2>> st;
    st.init(cmp + 69);

    for (int i = 0; i < n; ++i) {
        vector<array<int, 2>> upds;

        array<int, 2> mx = {0, -1};
        for (auto [l, r] : segs[i]) {
            mx = max(mx, st.query(mp[l], mp[r]));
            upds.push_back({l, r});
        }

        par[i] = mx[1];

        for (auto [l, r] : upds)
            st.upd(mp[l], mp[r], array<int, 2>{mx[0] + 1, i});

        // for (int i = 0; i < cmp; ++i)
            // cout << st.query(i, i)[0] << " "; cout << '\n';
    }

    array<int, 2> ret = st.query(0, cmp + 10);

    cout << n - ret[0] << '\n';
    // cout << ret[1] << '\n';

    // for (int i = 0; i < n; ++i)
        // cout << i << " " << par[i] << '\n';

    set<int> have;
    int cur = ret[1];
    while (cur >= 0) {
        have.insert(cur);
        cur = par[cur];
    }
    
    for (int i = 0; i < n; ++i)
        if (!have.count(i))
            cout << i + 1 << " ";
    cout << '\n';
}

