#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Segtree {{{
template<class T> struct ST {
    static constexpr T ID = 0; // or whatever ID
    inline T comb(T a, T b) { return a + b; } // or whatever function

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

// BIT {{{
template<class T> struct BIT {
    int sz;
    vector<T> bit;

    void init(int _sz) {
        sz = _sz;
        bit.resize(sz, 0);
    }
    void upd(int i, T x) {
        for (i += 5; i < sz; i += i & -i)
            bit[i] += x;
    }
    T query(int i) {
        T ret = 0;
        for (i += 5; i; i -= i & -i)
            ret += bit[i];
        return ret;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
// }}}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    ST<int> st;
    st.init(a);

    BIT<int> ft[3];
    BIT<ll> pos[3];
    for (int i = 0; i < 3; ++i) {
        ft[i].init(n + 69);
        pos[i].init(n + 69);
    }


    for (int i = 0; i < n; ++i) {
        ft[a[i]].upd(i, 1);
        pos[a[i]].upd(i, i);
    }

    ll res = 0;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z, --x, --z;

        ft[a[x]].upd(x, -1);
        pos[a[x]].upd(x, -x);
        a[x] = y;
        ft[a[x]].upd(x, 1);
        pos[a[x]].upd(x, x);
        st.upd(x, y);

        int bef = st.query(0, z), aft = st.query(z + 1, n - 1);
        // cout << "> " << bef << " " << aft << '\n';
        if (bef == aft)
            continue;

        int dif = aft - bef;
        if (abs(dif) & 1) {
            res += -1;
            continue;
        }

        int lcnt[3], rcnt[3];
        int f = 1;
        for (int i = 1; i < 3; ++i) {
            lcnt[i] = ft[i].query(0, z);
            rcnt[i] = ft[i].query(z + 1, n - 1);
        }

        if (dif < 0) {
            dif *= -1;
            f = 2;
            for (int i = 1; i < 3; ++i)
                swap(lcnt[i], rcnt[i]);
        }

        int need = dif / 2;
        if (min(rcnt[2], lcnt[1]) < need) {
            res += -1;
            continue;
        }

        int lo = 0, hi = z;
        while (lo < hi) {
            int m = lo + hi + 1 >> 1;

            if (ft[f].query(m, z) >= need)
                lo = m;
            else
                hi = m - 1;
        }

        // cout << "! " << lo << '\n';

        ll und = pos[f].query(lo, z);

        lo = z + 1, hi = n - 1;
        while (lo < hi) {
            int m = lo + hi >> 1;

            if (ft[3 - f].query(z + 1, m) >= need)
                hi = m;
            else
                lo = m + 1;
        }

        // cout << "> " << lo << '\n';

        ll ovr = pos[3 - f].query(z + 1, lo);

        // cout << "% " << und << " " << ovr << '\n';

        res += ovr - und;
    }

    cout << res << '\n';
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

