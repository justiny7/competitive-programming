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

const int MOD = 998244353;
using Mint = mi<MOD>;

const int N = 1e5 + 69;
int n, dp[N];
vector<int> adj[N];
Mint ans[N];
bool ok;

void dfs(int x, int v = 1, int p = 0) {
    if (!ok)
        return;

    for (int u : adj[v])
        if (u != p)
            dfs(x, u, v);

    if (dp[v] % x) {
        if (p)
            ++dp[v];
        if (dp[v] % x) {
            ok = 0;
            return;
        }
    } else {
        ++dp[p];
    }
}

void solve() {
    read(n);

    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        ans[i] = 0;
    }

    for (int i = 1, u, v; i < n; ++i) {
        read(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans[1] = binpow(Mint(2), n - 1);
    for (int i = 2; i < n; ++i) {
        if ((n - 1) % i)
            continue;

        memset(dp, 0, sizeof(dp));
        ok = 1;
        
        dfs(i);
        ans[i] = ok;
    }

    for (int i = n; i; --i)
        for (int j = i * 2; j <= n; j += i)
            ans[i] -= ans[j];

    for (int i = 1; i <= n; ++i)
        write(ans[i], " \n"[i == n]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

