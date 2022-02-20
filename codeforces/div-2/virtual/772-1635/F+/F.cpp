#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 3e5 + 69;
int n, q;
ll x[N], w[N], res[N];
vector<int> upd[N];
vector<array<int, 2>> qu[N];

// Segtree {{{
template<class T> struct ST {
    static constexpr T ID = LLONG_MAX; // or whatever ID
    inline T comb(T a, T b) { return min(a, b); } // or whatever function

    int sz;
    vector<T> t;

    void init(int _sz, T val = ID) {
        t.assign((sz = _sz) << 1, ID);
    }
    void init(vector<T> &v) {
        t.resize((sz = v.size()) << 1);
        for (int i = 0; i < sz; ++i)
            t[i + sz] = v[i];
        for (int i = sz - 1; i; --i)
            t[i] = comb(t[i << 1], t[i << 1 | 1]);
    }
    void upd(int i, T x) {
        for (t[i += sz] = x; i > 1; i >>= 1)
            t[i >> 1] = comb(t[i], t[i ^ 1]);
    }
    T query(int l, int r) {
        T ql = ID, qr = ID;
        for (l += sz, r += sz + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ql = comb(ql, t[l++]);
            if (r & 1) qr = comb(t[--r], qr);
        }
        return comb(ql, qr);
    }
};
// }}}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    cin >> n >> q;
    
    for (int i = 1; i <= n; ++i)
        cin >> x[i] >> w[i];

    // nearest smaller element
    stack<int> st;
    for (int i = 1; i <= n; ++i) {
        while (st.size() && w[i] < w[st.top()])
            st.pop();
        if (st.size())
            upd[i].push_back(st.top());
        st.push(i);
    }

    while (st.size())
        st.pop();

    for (int i = n; i; --i) {
        while (st.size() && w[i] < w[st.top()])
            st.pop();
        if (st.size())
            upd[st.top()].push_back(i);
        st.push(i);
    }

    /*
    for (int i = 1; i <= n; ++i) {
        cout << "pos " << i << ":\n";
        for (int j : upd[i])
            cout << j << " ";
        cout << '\n';
    }
    */

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        qu[r].push_back({l, i});
    }

    ST<ll> seg;
    seg.init(N);
    for (int i = 1; i <= n; ++i) {
        if (i > 1)
            upd[i].push_back(i - 1);

        for (int j : upd[i]) {
            ll v = ((w[i] + w[j]) * abs(x[i] - x[j]));
            if (v < seg.query(j, j))
                seg.upd(j, v);
        }
        for (auto [j, ind] : qu[i])
            res[ind] = seg.query(j, i);
    }

    for (int i = 0; i < q; ++i)
        cout << res[i] << '\n';

}

