#include <bits/stdc++.h>
using namespace std;

const int MX = 4e5 + 69;

// Segtree {{{
template<class T> struct ST {
    static constexpr T ID = 1e9; // or whatever ID
    inline T comb(T a, T b) { return min(a, b); } // or whatever function

    int sz;
    vector<T> t;

    void init(int _sz, T val = ID) {
        t.assign((sz = _sz) << 1, ID);
    }
    void init(vector<T> v) {
        t.resize((sz = v.size()) << 1);
        for (int i = 0; i < sz; ++i)
            t[i + sz] = v[i];
        for (int i = sz - 1; i; --i)
            t[i] = comb(t[i << 1], t[i << 1 | 1]);
    }
    void upd(int i, T x) {
        for (t[i += sz] += x; i > 1; i >>= 1)
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

    int q, x;
    cin >> q >> x;

    ST<int> st;
    st.init(vector<int>(MX));

    while (q--) {
        int c;
        cin >> c;

        st.upd(c % x, 1);

        int all = st.query(0, x - 1);
        // cout << "! " << all << '\n';

        int lo = 0, hi = x - 1, best = -1;
        while (lo <= hi) {
            int m = lo + hi >> 1;
            // cout << "? " << m << " " << st.query(0, m) << '\n';

            if (st.query(0, m) > all)
                lo = m + 1, best = m;
            else
                hi = m - 1;
        }

        // cout << "> " << best << '\n';

        int res = x * all;
        if (~best)
            res += best + 1;

        cout << res << '\n';
    }
}

