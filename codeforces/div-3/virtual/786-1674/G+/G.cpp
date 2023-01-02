#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, m;
int in[N], out[N], dp[N];
vector<int> adj[N];

void dfs(int v) {
    dp[v] = 0;
    if (out[v] < 2)
        return;

    for (int u : adj[v]) {
        if (in[u] < 2)
            continue;
        if (dp[u] < 0)
            dfs(u);

        dp[v] = max(dp[v], dp[u] + 1);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++in[v], ++out[u];
    }

    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; ++i)
        if (dp[i] < 0)
            dfs(i);

    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = max(res, dp[i] + 1);

    cout << res << '\n';
}

