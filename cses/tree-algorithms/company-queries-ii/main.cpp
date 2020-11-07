//Binary lifting for LCA
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e5+1, mxL=19;
int n, q, dep[mxN], dp[mxN][mxL];
vector<int> adj[mxN];

void dfs(int v=1, int p=1, int d=0) {
    dp[v][0]=p, dep[v]=d;
    for (int i=1; i<mxL; ++i)
        dp[v][i]=dp[dp[v][i-1]][i-1];
    for (int u:adj[v])
        if (u!=p)
            dfs(u, v, d+1);
}

int lca(int a, int b) {
    if (dep[a]<dep[b])
        swap(a, b);
    int l=0;
    for (; (1<<l)<=dep[a]; ++l);
    for (int i=l-1; i>=0; --i)
        if (dep[a]-(1<<i)>=dep[b])
            a=dp[a][i];
    if (a==b)
        return a;
    for (int i=l; i>=0; --i)
        if (dp[a][i]!=dp[b][i])
            a=dp[a][i], b=dp[b][i];
    return dp[a][0];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=2; i<=n; ++i) {
        int a; cin >> a;
        adj[i].pb(a);
        adj[a].pb(i);
    }
    dfs();
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
}
