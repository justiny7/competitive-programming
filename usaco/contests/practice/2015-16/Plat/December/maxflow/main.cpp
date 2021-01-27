#include <bits/stdc++.h>
using namespace std;

const int mxN=5e4+1, mxL=20;
int n, k, ans, pref[mxN], dp[mxN][mxL], dep[mxN];
vector<int> adj[mxN];

void dfs(int v=1, int p=0, int d=0) {
    dp[v][0]=p, dep[v]=d;
    for (int i=1; i<mxL; ++i)
        dp[v][i]=dp[dp[v][i-1]][i-1];
    for (int u:adj[v])
        if (u^p)
            dfs(u, v, d+1);
}
void dfs2(int v=1, int p=0) {
    for (int u:adj[v])
        if (u^p) {
            dfs2(u, v);
            pref[v]+=pref[u];
        }
}
int lca(int a, int b) {
    if (dep[a]<dep[b])
        swap(a, b);
    for (int i=mxL-1; ~i; --i)
        if (dep[a]-(1<<i)>=dep[b])
            a=dp[a][i];
    if (a==b)
        return a;
    for (int i=mxL-1; ~i; --i)
        if (dp[a][i]^dp[b][i])
            a=dp[a][i], b=dp[b][i];
    return dp[a][0];
}

int main() {
    ifstream cin("maxflow.in");
    ofstream cout("maxflow.out");
    cin >> n >> k;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    while (k--) {
        int a, b, l;
        cin >> a >> b;
        l=lca(a, b);
        ++pref[a], ++pref[b], --pref[l], --pref[dp[l][0]];
    }
    dfs2();
    for (int i=1; i<=n; ++i)
        ans=max(ans, pref[i]);
    cout << ans << '\n';
}

