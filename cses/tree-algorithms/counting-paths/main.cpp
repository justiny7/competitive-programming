//Prefsum on tree
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e5+1, mxL=19;
int n, m, dp[mxN][mxL], pref[mxN], dep[mxN];
vector<int> adj[mxN];

void dfs(int v=1, int p=0, int d=0) {
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

int get_ans(int v=1, int p=0) {
    for (int u:adj[v])
        if (u!=p)
            pref[v]+=get_ans(u, v);
    return pref[v];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    while (m--) {
        int a, b, LCA;
        cin >> a >> b;
        LCA=lca(a, b);
        ++pref[a], ++pref[b], --pref[LCA], --pref[dp[LCA][0]];
    }
    get_ans();
    for (int i=1; i<=n; ++i) {
        if (i>1)
            cout << " ";
        cout << pref[i];
    }
    cout << '\n';
}
