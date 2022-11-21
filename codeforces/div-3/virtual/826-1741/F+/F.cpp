#include <bits/stdc++.h>
using namespace std;


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

void solve() {
    int n;
    cin >> n;

    multiset<int> ms;
    vector<int> pts;

    vector<vector<array<int, 3>>> seg(n + 1);
    for (int i = 0; i < n; ++i) {
        int l, r, c;
        cin >> l >> r >> c;

        if (l > r)
            swap(l, r);

        seg[c].push_back({l, r, i});
        ms.insert(l);
        ms.insert(r);

        pts.push_back(l);
        pts.push_back(r);
    }

    vector<int> res(n, INT_MAX);
    for (int i = 0; i <= n; ++i) {
        for (auto [l, r, ind] : seg[i]) {
            ms.erase(ms.find(l));
            ms.erase(ms.find(r));
        }

        for (auto [l, r, ind] : seg[i]) {
            auto rt = ms.lower_bound(r),
                 lf = ms.lower_bound(l);

            if (rt != ms.end())
                res[ind] = min(res[ind], *rt - r);
            if (lf != ms.begin())
                res[ind] = min(res[ind], l - *prev(lf));
        }

        for (auto [l, r, ind] : seg[i]) {
            ms.insert(l);
            ms.insert(r);
        }
    }

    pts.push_back(0);
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    auto get = [&](int x) -> int {
        return lower_bound(pts.begin(), pts.end(), x) - pts.begin();
    };

    LZ_ST<int> st;
    st.init(n * 2 + 5);
    for (int i = 1; i <= n; ++i)
        for (auto [l, r, ind] : seg[i])
            st.upd(get(l), get(r), 1);

    for (int i = 1; i <= n; ++i) {
        for (auto [l, r, ind] : seg[i])
            st.upd(get(l), get(r), -1);

        for (auto [l, r, ind] : seg[i])
            if (st.query(get(l), get(r)))
                res[ind] = 0;

        for (auto [l, r, ind] : seg[i])
            st.upd(get(l), get(r), 1);
    }
    
    for (int i : res)
        cout << i << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

