#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, targ, sz[N], dep[N], par[N];
vector<int> adj[N];
bool vis[N];

int query(char c, int v) {
    cout << c << " " << v << endl;
    int ret; cin >> ret;
    return ret;
}

int dfs_sz(int v, int p = 0) {
    sz[v] = 1;
    for (int u : adj[v])
        if (!vis[u] && u != p)
            sz[v] += dfs_sz(u, v);
    return sz[v];
}
int dfs_centroid(int tot, int v, int p = 0) {
    for (int u : adj[v])
        if (!vis[u] && u != p && sz[u] * 2 >= tot)
            return dfs_centroid(tot, u, v);
    return v;
}
void decomp(int x = 1) {
    int v = dfs_centroid(dfs_sz(x), x);
    vis[v] = 1;

    int d = query('d', v);
    if (d == 0) {
        query('!', v);
        exit(0);
    }

    if (dep[v] + d == targ)
        decomp(query('s', v));
    else
        decomp(par[v]);
}

void dfs_dep(int v = 1, int p = 0, int d = 0) {
    dep[v] = d, par[v] = p;

    for (int u : adj[v])
        if (u != p)
            dfs_dep(u, v, d + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    targ = query('d', 1);
    dfs_dep(); decomp();

    assert(false);
}
