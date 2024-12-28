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

    BIT<int> ft[4];
    for (int i = 0; i < 4; ++i)
        ft[i].init(n + 69);

    for (int i = 0; i < n; ++i)
        ft[a[i]].upd(i, 1);

    ll res = 0;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z, --x, --z;

        ft[a[x]].upd(x, -1);
        ft[a[x] = y].upd(x, 1);
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

        int lcnt[4], rcnt[4];
        for (int i = 1; i < 4; ++i) {
            lcnt[i] = ft[i].query(0, z);
            rcnt[i] = ft[i].query(z + 1, n - 1);
        }

        if (dif < 0) {
            dif *= -1;
            for (int i = 1; i < 4; ++i)
                swap(lcnt[i], rcnt[i]);
        }

        int four = min(lcnt[1], rcnt[3]);
        int need = min(four, dif / 4);
        int here = need;

        dif -= need * 4;
        lcnt[1] -= need, rcnt[3] -= need;
        lcnt[3] += need, rcnt[1] += need;

        int two = min(lcnt[2], rcnt[3]);
        two = max(two, min(lcnt[1], rcnt[2]));

        if (two * 2 >= dif) {
            here += dif / 2;
            res += here;
        } else {
            res += -1;
        }
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

