#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 69;
int n, ans, dp[N];
vector<int> adj[N];
vector<pair<int, int>> vals[N];

void dfs(int v = 1, int p = 0) {
    for (int u : adj[v]) {
        if (u == p)
            continue;

        dfs(u, v);
        vals[v].emplace_back(dp[u], u);
    }

    vals[v].emplace_back(0, 0);
    sort(vals[v].rbegin(), vals[v].rend());
    dp[v] = vals[v][0].first + 1 + max(0, (int)adj[v].size() - 2);
}
void reroot(int v = 1, int p = 0) {
    vector<int> here;
    for (int u : adj[v])
        here.push_back(dp[u]);
    sort(here.rbegin(), here.rend());

    int ret = adj[v].size() + here[0];
    if (here.size() > 1)
        ret += here[1] - 1;
    ans = max(ans, ret);

    for (int u : adj[v]) {
        if (u == p)
            continue;

        if (u == vals[v][0].second) {
            dp[v] -= dp[u];
            if (vals[v].size() > 1)
                dp[v] += vals[v][1].first;
        }
        if (dp[v] > vals[u][0].first) {
            dp[u] -= vals[u][0].first;
            dp[u] += dp[v];
        }

        reroot(u, v);

        if (dp[v] > vals[u][0].first) {
            dp[u] -= dp[v];
            dp[u] += vals[u][0].first;
        }
        if (u == vals[v][0].second) {
            if (vals[v].size() > 1)
                dp[v] -= vals[v][1].first;
            dp[v] += dp[u];
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        vals[i].clear();
        dp[i] = 0;
    }

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = 0;
    dfs(); reroot();
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--)
        solve();
}
