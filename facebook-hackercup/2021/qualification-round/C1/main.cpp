#include <bits/stdc++.h>
using namespace std;

const int N = 69;
int n, c[N], dp[N];
vector<int> adj[N];

void dfs(int v = 1, int p = 0) {
    int mx = 0;
    for (int u : adj[v]) {
        if (u == p)
            continue;
        
        dfs(u, v);
        mx = max(mx, dp[u]);
    }

    dp[v] += mx;
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> c[i], dp[i] = c[i];
        adj[i].clear();
    }

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    vector<int> ret;
    for (int u : adj[1])
        ret.push_back(dp[u]);

    sort(ret.rbegin(), ret.rend());
    int ans = c[1];
    if (ret.size())
        ans += ret[0];
    if (ret.size() > 1)
        ans += ret[1];

    cout << ans << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

