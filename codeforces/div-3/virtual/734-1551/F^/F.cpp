#include <bits/stdc++.h>
using namespace std;

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

const int N = 169;
int n, k, deps[N][N];
vector<int> adj[N];
Mint ans;

void dfs(int v, int p, int pp, int d = 1) {
    ++deps[pp][d];

    for (int u : adj[v])
        if (u != p)
            dfs(u, v, pp, d + 1);
}

void solve() {
    cin >> n >> k;

    for (int i = 1; i <= n; ++i)
        adj[i].clear();

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (k == 2)
        return void(cout << (n * (n - 1) / 2) << '\n');

    ans = 0;
    for (int st = 1; st <= n; ++st) {
        memset(deps, 0, sizeof(deps));
        for (int u : adj[st])
            dfs(u, st, u);

        int sz = adj[st].size();
        for (int d = 1; d < N; ++d) {
            vector<vector<Mint>> dp(sz + 1, vector<Mint>(k + 1));

            dp[0][0] = 1;
            for (int i = 0; i < sz; ++i) {
                for (int j = 0; j <= k; ++j) {
                    dp[i + 1][j] += dp[i][j];
                    if (j < k)
                        dp[i + 1][j + 1] += dp[i][j] * deps[adj[st][i]][d];
                }
            }

            ans += dp[sz][k];
        }
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--)
        solve();
}
