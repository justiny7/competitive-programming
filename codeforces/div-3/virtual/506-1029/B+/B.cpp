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
    const T ID = 0; // or whatever ID
    inline T comb(T a, T b) { return max(a, b); } // or whatever function

    int sz;
    vector<T> t;

    void init(int _sz, bool zero) { t.resize((sz = _sz) << 1, zero ? 0 : ID); }
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
    int n; read(n);

    ST<int> dp;
    dp.init(n + 1, 1);

    vector<int> a(n);
    int ptr = 0;
    for (int i = 0; i < n; ++i) {
        read(a[i]);

        while (a[ptr] * 2 < a[i])
            ++ptr;

        if (ptr == i)
            dp.upd(i, 1);
        else
            dp.upd(i, 1 + dp.query(ptr, i - 1));
    }

    print(dp.query(0, n));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
    solve();
}
