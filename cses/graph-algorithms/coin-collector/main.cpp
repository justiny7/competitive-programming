//Idea - treat scc's as a single node with their combined coins, because you can traverse
//from any vertex to any other vertex within a scc
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=1e5+1;
int n, m, scc[mxN], out[mxN], cnt;
ll c[mxN], c2[mxN], dp[mxN], ans;
vector<int> adj[mxN], radj[mxN], tadj[mxN], ord;
bool vis[mxN];

void dfs(int v) {
    vis[v]=1;
    for (int u:adj[v])
        if (!vis[u])
            dfs(u);
    ord.pb(v);
}
void dfs2(int v) {
    scc[v]=cnt;
    for (int u:radj[v])
        if (!scc[u])
            dfs2(u);
}
void dfs3(int v) {
    if (dp[v])
        return;
    dp[v]=c2[v];
    ll mx=0;
    for (int u:tadj[v]) {
        dfs3(u);
        mx=max(mx, dp[u]);
    }
    dp[v]+=mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        cin >> c[i];
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        radj[b].pb(a);
    }
    for (int i=1; i<=n; ++i)
        if (!vis[i])
            dfs(i);
    for (int i=n-1; ~i; --i) {
        int v=ord[i];
        if (!scc[v])
            ++cnt, dfs2(v);
    }
    for (int i=1; i<=n; ++i) {
        c2[scc[i]]+=c[i];
        for (int u:adj[i])
            if (scc[i]^scc[u])
                tadj[scc[u]].pb(scc[i]), ++out[scc[i]];
    }
    for (int i=1; i<=cnt; ++i)
        if (!out[i])
            dfs3(i), ans=max(ans, dp[i]);
    cout << ans << '\n';
}

