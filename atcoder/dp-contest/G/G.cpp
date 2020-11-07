#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, m, dp[mxN], ans;
vector<int> adj[mxN];

void dfs(int v) {
    dp[v]=1;
    for (int u:adj[v]) {
        if (!dp[u])
            dfs(u);
        dp[v]=max(dp[v], 1+dp[u]);
        ans=max(ans, dp[v]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    for (int i=1; i<=n; ++i)
        if (!dp[i])
            dfs(i);
    cout << ans-1 << '\n';
}
