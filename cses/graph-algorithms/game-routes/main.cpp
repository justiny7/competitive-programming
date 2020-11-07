#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1, MOD=1e9+7;
int n, m, dp[mxN];
vector<int> adj[mxN];

int dfs(int v) {
    if (dp[v])
        return dp[v];
    int tot=0;
    for (int u:adj[v])
        tot=(tot+dfs(u))%MOD;
    return dp[v]=tot;
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[b].pb(a);
    }
    dp[1]=1;
    cout << dfs(n) << '\n';
}
