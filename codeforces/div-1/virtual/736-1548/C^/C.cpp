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

// Modular Int {{{
template<int MD> struct mi {
    int v;
    explicit operator int() const { return v; }

    mi(long long _v = 0) {
        v = (-MD <= _v && _v < MD) ? _v : _v % MD;
        v = (v < 0) ? v + MD : v;
    }

    friend bool operator==(const mi &a, const mi &b) { return a.v == b.v; }
    friend bool operator!=(const mi &a, const mi &b) { return !(a == b); }
    friend bool operator<(const mi &a, const mi &b) { return a.v < b.v; }

    mi &operator+=(const mi &o) { if ((v += o.v) >= MD) v -= MD; return *this; }
    mi &operator-=(const mi &o) { if ((v -= o.v) < 0) v += MD; return *this; }
    mi &operator*=(const mi &o) { v = 1LL * v * o.v % MD; return *this; }
    mi &operator/=(const mi &o) { return (*this) *= inv(o); }

    friend mi inv(const mi &m) { return binpow(m, MD - 2); }
    friend mi binpow(mi b, long long e) {
        mi ret = 1;
        for (; e; e >>= 1, b *= b)
            if (e & 1)
                ret *= b;
        return ret;
    }

    friend mi operator+(mi a, const mi &b) { return a += b; }
    friend mi operator-(mi a, const mi &b) { return a -= b; }
    friend mi operator*(mi a, const mi &b) { return a *= b; }
    friend mi operator/(mi a, const mi &b) { return a /= b; }

    friend istream &operator>>(istream &i, mi &m) { long long x; i >> x; m.v = x; return i; }
    friend ostream &operator<<(ostream &o, const mi &m) { o << m.v; return o; }
};
// }}}

const int MOD = 1e9 + 7;
using Mint = mi<MOD>;

const int N = 1e6 + 69;
Mint fact[N * 3];

Mint nCr(int n, int r) {
    if (n < r)
        return 0;
    return fact[n] / (fact[r] * fact[n - r]);
}

// Let dp[i][j] = sum of n = 1 to N of (3 * n + j) choose i
// dp[i][0] + dp[i][1] + dp[i][2] = 3(N + 1) choose (i + 1)
// dp[i + 1][0] = 3(N + 1) choose (i + 2) - dp[i + 1][1] - dp[i + 1][2]
// dp[i][0] + dp[i + 1][0] = dp[i + 1][1]
// dp[i][1] + dp[i + 1][1] = dp[i + 1][2]

// dp[i + 1][0] = 3(N + 1) choose (i + 2) - (dp[i][0] + dp[i + 1][0]) - (dp[i][1] + dp[i][0] + dp[i + 1][0])
// 3 * dp[i + 1][0] = 3(N + 1) choose (i + 2) - 2 * dp[i][0] - dp[i][1]
Mint dp[N * 3][3];

void solve() {
    int n, q;
    read(n, q);

    for (int i = 0; i < 3; ++i)
        dp[0][i] = n + 1;
    for (int i = 0; i < n * 3; ++i) {
        dp[i + 1][0] = nCr(n * 3 + 3, i + 2);
        dp[i + 1][0] -= (dp[i][0] * 2 + dp[i][1]);
        dp[i + 1][0] /= 3;
        dp[i + 1][1] = dp[i][0] + dp[i + 1][0];
        dp[i + 1][2] = dp[i][1] + dp[i + 1][1];
    }

    while (q--) {
        int x;
        read(x);

        print(dp[x][0]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fact[0] = 1;
    for (int i = 1; i < N * 3; ++i)
        fact[i] = fact[i - 1] * i;

    // int t; read(t);
    // while (t--)
        solve();
}

