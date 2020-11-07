//Binary lifting
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e5+1, mxL=19;
int n, q, dp[mxN][mxL], dep[mxN];
vector<int> adj[mxN];

void dfs(int v=1, int p=1, int d=0) {
    dp[v][0]=p, dep[v]=d;
    for (int i=1; i<mxL; ++i)
        dp[v][i]=dp[dp[v][i-1]][i-1];
    for (int u:adj[v])
        if (u!=p)
            dfs(u, v, d+1);
}

int query(int v, int k) {
    if (k>dep[v])
        return -1;
    int ans=v, c=k;
    for (int i=mxL-1; i>=0; --i)
        if (dp[ans][i] && (1<<i)<=c)
            ans=dp[ans][i], c-=(1<<i);
    return ans;
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
        int x, k;
        cin >> x >> k;
        cout << query(x, k) << '\n';
    }
}
