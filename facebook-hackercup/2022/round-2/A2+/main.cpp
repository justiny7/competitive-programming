#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define uid(a, b) uniform_int_distribution<ll>((a), (b))(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e6 + 69;
const ll MOD = 2e18 - 69 * 69;
ll hsh[N];
map<ll, int> mp;

// Segtree {{{
template<class T> struct ST {
    static constexpr T ID = 0; // or whatever ID
    inline T comb(T a, T b) { return a ^ b; } // or whatever function

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

// Segtree {{{
template<class T> struct ST2 {
    static constexpr T ID = 0; // or whatever ID
    inline T comb(T a, T b) { return (a + b + MOD) % MOD; } // or whatever function

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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<set<int>> pos(N);
    for (int i = 0; i < n; ++i)
        pos[a[i]].insert(i);

    vector<ll> a_hsh(n);
    for (int i = 0; i < n; ++i)
        a_hsh[i] = hsh[a[i]];

    ST<ll> st;
    st.init(a_hsh);
    ST2<ll> st2;
    st2.init(a_hsh);

    int res = 0;
    auto ok = [&](int l, int r, int rem, ll cur) {
        int m = l + r >> 1;
        if (rem >= m)
            --m;

        ll bef = st2.query(l, m), aft = st2.query(m + 1, r);
        if (rem < (l + r >> 1))
            bef = (bef - cur + MOD) % MOD;
        else
            aft = (aft - cur + MOD) % MOD;

        return bef == aft;
    };

    int q;
    cin >> q;
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;

        if (t & 1) {
            --l;
            pos[a[l]].erase(l);
            st.upd(l, hsh[r]);
            st2.upd(l, hsh[r]);
            pos[a[l] = r].insert(l);
        } else {
            if (l == r)
                ++res;
            else {
                --l, --r;
                ll cur = st.query(l, r);

                if (mp.count(cur)) {
                    int o = mp[cur];
                    // cout << "odd one: " << o << '\n';

                    int fst = *pos[o].lower_bound(l);
                    int lst = *prev(pos[o].upper_bound(r));

                    if (ok(l, r, fst, cur) || ok(l, r, lst, cur))
                        // cout << "OK!\n",
                        ++res;
                }
            }
        }
    }

    cout << res << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int i = 0; i < N; ++i) {
        ll here = uid(10101, 1e18 - 1);
        assert(!mp.count(here));
        hsh[i] = here;
        mp[here] = i;
    }

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

