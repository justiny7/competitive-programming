#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, ans[mxN], dp[mxN];
vector<int> adj[mxN];

void dfs(int v=1, int p=0) {
    for (int u:adj[v])
        if (u^p) {
            dfs(u, v);
            dp[v]+=max(0, dp[u]);
        }
}
void dfs2(int v=1, int p=0) {
    ans[v]=dp[v];
    for (int u:adj[v])
        if (u^p) {
            dp[v]-=max(0, dp[u]);
            dp[u]+=max(0, dp[v]);
            dfs2(u, v);
            dp[u]-=max(0, dp[v]);
            dp[v]+=max(0, dp[u]);
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        int b; cin >> b;
        dp[i]=(b?1:-1);
    }
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(); dfs2();
    for (int i=1; i<=n; ++i)
        cout << ans[i] << " \n"[i==n];
}

