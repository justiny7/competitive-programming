#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e5+1;
int n, dp[mxN][2], d_v=-1, max_v;
vector<int> adj[mxN];

void dfs(int store, int v, int p=-1, int dist=0) {
    if (dist>d_v)
        d_v=dist, max_v=v;
    if (store<2)
        dp[v][store]=dist;
    for (int u:adj[v])
        if (u!=p)
            dfs(store, u, v, dist+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(2, 1);
    d_v=-1;
    dfs(0, max_v);
    d_v=-1;
    dfs(1, max_v);
    for (int i=1; i<=n; ++i) {
        if (i>1)
            cout << " ";
        cout << max(dp[i][0], dp[i][1]);
    }
    cout << '\n';
}
