#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, ans, c[mxN];
vector<int> adj[mxN];

void dfs(int v=1, int p=0) {
    while (c[v]-1<adj[v].size()-(p!=0))
        ++ans, c[v]*=2;
    for (int u:adj[v])
        if (u^p)
            ++ans, c[u]=1, dfs(u, v);
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
    c[1]=1;
    dfs();
    cout << ans << '\n';
}

