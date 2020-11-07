#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, m, p[mxN];
vector<int> adj[mxN], ans;
bool vis[mxN], vis2[mxN];

void dfs(int v, int par=-1) {
    vis[v]=1, p[v]=par;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs(u, v);
        else if (vis[u] && !vis2[u]){
            ans.pb(u);
            while (v!=u) {
                ans.pb(v);
                v=p[v];
            }
            if (v<0) {
                ans.clear();
                continue;
            }
            ans.pb(u);
            cout << ans.size() << '\n';
            for (int i=ans.size()-1; i>=0; --i) {
                cout << ans[i];
                if (i)
                    cout << " ";
            }
            cout << '\n';
            exit(0);
        }
    }
    vis2[v]=1;
}

int main(void) {
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    for (int i=1; i<=n; ++i)
        if (!vis[i]) {
            memset(vis, 0, sizeof(vis));
            dfs(i);
        }
    cout << "IMPOSSIBLE\n";
}

