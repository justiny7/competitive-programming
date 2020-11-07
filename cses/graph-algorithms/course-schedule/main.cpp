#include <bits/stdc++.h>
#define pb push_back
using namespace std;
//Toposort
const int mxN=1e5+1;
int n, m;
vector<int> adj[mxN], ans;
bool vis[mxN], vis2[mxN];

bool dfs(int v) {
    vis[v]=1;
    for (int u:adj[v])
        if ((vis[u] && !vis2[u]) || (!vis[u] && !dfs(u)))
            return 0;
    vis2[v]=1;
    ans.pb(v);
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    for (int i=1; i<=n; ++i)
        if (!vis[i] && !dfs(i)) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    for (int i=ans.size()-1; i>=0; --i) {
        cout << ans[i];
        if (i)
            cout << " ";
    }
    cout << '\n';
}
