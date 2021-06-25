#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 269, L = 10, M = 1e9 + 7;
int n, dep[N], lift[N][L];
ll ans, dp[N][N];
vector<int> adj[N];

void dfs(int v, int p, int d = 0) {
    dep[v] = d;

    lift[v][0] = p;
    for (int i = 1; i < L; ++i)
        lift[v][i] = lift[lift[v][i - 1]][i - 1];

    for (int u : adj[v])
        if (u != p)
            dfs(u, v, d + 1);
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) // now, u is deeper
        swap(u, v);

    int dif = dep[u] - dep[v];
    for (int i = L - 1; ~i; --i)
        if (dif & (1 << i))
            u = lift[u][i];

    if (u == v)
        return u;

    for (int i = L - 1; ~i; --i)
        if (lift[v][i] != lift[u][i])
            v = lift[v][i], u = lift[u][i];

    return lift[v][0];
}

ll binpow(ll b, ll e) {
    ll ret = 1;
    for (; e; (b *= b) %= M, e >>= 1)
        if (e & 1)
            (ret *= b) %= M;
    return ret;
}
ll inv(ll x) {
    return binpow(x, M - 2);
}

int main() {
    for (int i = 0; i < N; ++i)
        dp[0][i] = 1, dp[i][0] = 0;
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            dp[i][j] = ((M + 1) / 2) * ((dp[i - 1][j] + dp[i][j - 1]) % M) % M;

    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int v = 1; v <= n; ++v) {
        dfs(v, v);

        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                int l = lca(i, j);
                (ans += dp[dep[j] - dep[l]][dep[i] - dep[l]]) %= M;
            }
        }
    }

    cout << (ans * inv(n)) % M << '\n';
}
