#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=101;
int n, m;
vector<int> adj[mxN];
bitset<mxN> vis;

void dfs(pii p, int v=0) {
    vis[v]=1;
    for (int u:adj[v]) {
        pii q=minmax(u, v);
        if (!vis[u] && q!=p)
            dfs(p, u);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    while (cin >> n >> m && (n || m)) {
        for (int i=0; i<n; ++i)
            adj[i].clear();
        vector<pii> edges;
        for (int i=0; i<m; ++i) {
            int a, b;
            cin >> a >> b;
            adj[a].pb(b);
            adj[b].pb(a);
            edges.pb(minmax(a, b));
        }
        bool f=1;
        for (int i=0; i<m; ++i) {
            vis.reset();
            dfs(edges[i]);
            f&=(vis.count()==n);
        }
        cout << (f?"No\n":"Yes\n");
    }
}

