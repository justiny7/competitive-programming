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
template<class T> bool ckmin(T &a, const T b) { return (b < a) ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T b) { return (a < b) ? a = b, 1 : 0; }

using ll = long long;

// }}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// mi {{{
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
    mi &operator*=(const mi &o) { v = static_cast<int>(static_cast<long long>(v) * o.v % MD); return *this; }
    mi &operator/=(const mi &o) { return (*this) *= inv(o); }

    friend mi binpow(mi b, long long e) {
        mi ret = 1;
        for (; e; e >>= 1, b *= b)
            if (e & 1)
                ret *= b;
        return ret;
    }
    friend mi inv(const mi &a) { return binpow(a, MD - 2); }

    mi operator-() { return mi(-v); }
    mi operator++() { return (*this) += 1; }
    mi operator--() { return (*this) -= 1; }
    friend mi operator+(mi a, const mi &b) { return a += b; }
    friend mi operator-(mi a, const mi &b) { return a -= b; }
    friend mi operator*(mi a, const mi &b) { return a *= b; }
    friend mi operator/(mi a, const mi &b) { return a /= b; }

    friend ostream &operator<<(ostream &o, const mi &m) { o << m.v; return o; }
    friend istream &operator>>(istream &i, mi &m) { long long x; i >> x; m.v = x; return i; }
};
// }}}

const int MOD = 1e9 + 7;
using Mint = mi<MOD>;

// without roadblocks, (h + w - 2) choose h - 1 (or w - 1)

const int H = 2e5 + 69, N = 2e3 + 69;
int n, h, w;
array<int, 2> b[N];
Mint dp[N], fact[H];

Mint nCr(int nn, int rr) {
    return fact[nn] / (fact[rr] * fact[nn - rr]);
}
Mint ways(int i, int j) {
    if (b[i][0] > b[j][0] || b[i][1] > b[j][1])
        return 0;

    int hor = b[j][0] - b[i][0] + 1, ver = b[j][1] - b[i][1] + 1;
    return nCr(hor + ver - 2, hor - 1);
}

void solve() {
    fact[0] = 1;
    for (int i = 1; i < H; ++i)
        fact[i] = fact[i - 1] * Mint(i);

    read(h, w, n);

    for (int i = 0; i < n; ++i)
        read(b[i]);
    sort(b, b + n);
    b[n++] = {h, w};

    for (int i = 0; i < n; ++i) {
        dp[i] = nCr(b[i][0] + b[i][1] - 2, b[i][0] - 1);
        for (int j = 0; j < n; ++j)
            if (i != j)
                dp[i] -= ways(j, i) * dp[j];

        //print(">", i, dp[i], b[i]);
    }

    print(dp[n - 1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
