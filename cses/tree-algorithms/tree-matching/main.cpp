#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e5+1;
int n, dp[mxN][2]; //0=free, 1=taken
vector<int> adj[mxN];

void dfs(int v=1, int p=-1) {
    for (int u:adj[v]) {
        if (u==p)
            continue;
        dfs(u, v);
        dp[v][0]+=max(dp[u][1], dp[u][0]); //if not taken, then cmax is max of taken/untaken children
    }
    for (int u:adj[v])
        if (u!=p)
            dp[v][1]=max(dp[v][1], dp[u][0]+1+dp[v][0]-max(dp[u][0], dp[u][1]));
}                //       matching v with u    subtracting contribution u had to dp[v][0]

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    cout << max(dp[1][0], dp[1][1]) << '\n';
}
