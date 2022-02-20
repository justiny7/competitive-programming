#include <bits/stdc++.h>
using namespace std;

// graph has to be bipartite
// wlog, color 0 = L, 1 = R
// build dag, get toposort
const int N = 2e5 + 69;
int n, m, col[N], vis[N], pos[N];
vector<int> adj[N], dadj[N], res;
vector<array<int, 2>> irr, dest;
bool bipartite = 1, cyc = 0;

void dfs_check(int v, int c) {
    col[v] = c;
    for (int u : adj[v]) {
        if (col[u] < 0)
            dfs_check(u, c ^ 1);
        else if (col[u] == col[v])
            bipartite = 0;
    }
}
void dfs_topo(int v) {
    vis[v] = 1;
    for (int u : dadj[v]) {
        if (!vis[u])
            dfs_topo(u);
        else if (vis[u] == 1)
            cyc = 1;
    }
    vis[v] = 2;
    res.push_back(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    while (m--) {
        int t, u, v;
        cin >> t >> u >> v;

        if (t & 1)
            irr.push_back({u, v});
        else
            dest.push_back({u, v});

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(col, -1, sizeof(col));
    for (int i = 1; i <= n; ++i)
        if (col[i] < 0)
            dfs_check(i, 0);

    if (!bipartite) {
        cout << "NO\n";
        return 0;
    }

    for (auto [u, v] : irr) {
        if (col[u])
            swap(u, v);
        dadj[v].push_back(u);
    }
    for (auto [u, v] : dest) {
        if (col[u])
            swap(u, v);
        dadj[u].push_back(v);
    }

    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs_topo(i);

    if (cyc) {
        cout << "NO\n";
        return 0;
    }

    for (int i = 0; i < n; ++i)
        pos[res[i]] = i;

    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << (col[i] ? 'R' : 'L') << " " << pos[i] << '\n';
}

