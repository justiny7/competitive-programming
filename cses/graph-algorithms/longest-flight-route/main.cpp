#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, m, dp[mxN], par[mxN];
vector<int> adj[mxN], path;
bool vis[mxN], vis2[mxN];

void dfs(int v=1) {
    vis[v]=1;
    for (int u:adj[v]) {
        if (!vis[u]) {
            par[u]=v;
            dfs(u);
        }
        if (dp[u]+1>dp[v])
            dp[v]=dp[u]+1, par[v]=u;
    }
}

void dfs2(int v=1) {
    vis2[v]=1;
    for (int u:adj[v])
        if (!vis2[u])
            dfs2(u);
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    dfs2();
    if (!vis2[n]) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    memset(dp, -0x3f, sizeof(dp));
    dp[n]=1;
    dfs();
    int v=1;
    while (v!=n) {
        path.pb(v);
        v=par[v];
    }
    path.pb(n);
    cout << path.size() << '\n';
    for (int i=0; i<path.size(); ++i) {
        if (i)
            cout << " ";
        cout << path[i];
    }
    cout << '\n';
}
