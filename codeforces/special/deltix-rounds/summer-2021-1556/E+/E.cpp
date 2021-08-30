#include <bits/stdc++.h>
using namespace std;

// TEMPLATE {{{

/* Macros */
#define all(x) (x).begin(), (x).end()
#define finish(...) return void(print(__VA_ARGS__))

/* Input */
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { for (T &i : a) read(i); }
template<class T> void read(vector<T> &v) { for (T &i : v) read(i); }

template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

/* Output */
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; for (T i : a) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T i : v) o << s << i, s = " "; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

/* Misc */
bool ckmin(auto &a, const auto &b) { return (a > b) ? a = b, 1 : 0; }
bool ckmax(auto &a, const auto &b) { return (a < b) ? a = b, 1 : 0; }

using ll = long long;

// }}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 1e5 + 69;
int n, q;
ll a[N], b[N], pa[N], pb[N], pref[N];
vector<array<int, 2>> qu[N];

// Segtree {{{
template<class T> struct ST {
    static constexpr T ID = {LLONG_MAX, LLONG_MIN}; // or whatever ID
    inline T comb(T a, T b) {
        array<ll, 2> ret;
        ret[0] = min(a[0], b[0]);
        ret[1] = max(a[1], b[1]);
        return ret;
    } // or whatever function

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
    read(n, q);
    
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        pa[i] = pa[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        read(b[i]);
        pb[i] = pb[i - 1] + b[i];
    }

    ST<array<ll, 2>> st;
    st.init(n + 69);
    for (int i = 1; i <= n; ++i) {
        pref[i] = b[i] - a[i] + pref[i - 1];
        st.upd(i, {pref[i], pref[i]});
    }

    while (q--) {
        int l, r;
        read(l, r);

        if (pa[r] - pa[l - 1] != pb[r] - pb[l - 1])
            print(-1);
        else {
            auto here = st.query(l, r);
            if (here[0] == pref[l - 1])
                print(here[1] - pref[l - 1]);
            else
                print(-1);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
        solve();
}

