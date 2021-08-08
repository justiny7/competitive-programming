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

// Segtree {{{
template<class T> struct ST {
    const T ID = -1; // or whatever ID
    inline T comb(T a, T b) {
        if (a < 0)
            return b;
        if (b < 0)
            return a;
        return gcd(a, b);
    } // or whatever function

    int sz;
    vector<T> t;

    void init(int _sz, T val = -1) { t.resize((sz = _sz) << 1, val); }
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
            if (l & 1)
                ql = comb(ql, t[l++]);
            if (r & 1)
                qr = comb(t[--r], qr);
        }
        return comb(ql, qr);
    }
};
// }}}

void solve() {
    int n;
    read(n);

    vector<ll> a(n), dif(n - 1);
    read(a);

    if (n == 1)
        finish(1);

    for (int i = 1; i < n; ++i)
        dif[i - 1] = abs(a[i] - a[i - 1]);

    ST<ll> st;
    st.init(dif);

    int l = 0, r = 0, ans = 1;
    while (l < n - 1) {
        if (r < l)
            r = l;

        // print(l, r);
        while (r + 1 < n - 1 && st.query(l, r + 1) > 1)
            ++r;

        if (st.query(l, r) > 1)
            ckmax(ans, r - l + 2);
        ++l;
    }

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

