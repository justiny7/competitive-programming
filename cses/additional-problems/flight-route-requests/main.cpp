#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, m, vis[N];
vector<int> adj[N], cmp[N];
bool f;

// DSU {{{
int par[N], sz[N];
int find(int v) {
    return v == par[v] ? v : par[v] = find(par[v]);
}
bool merge(int u, int v) {
    if ((u = find(u)) == (v = find(v)))
        return 0;
    if (sz[u] > sz[v])
        swap(u, v);
    par[u] = v, sz[v] += sz[u];
    return 1;
}
// }}}

void dfs(int v) {
    vis[v] = 1;
    for (int u : adj[v]) {
        if (vis[u] == 1)
            f = 1;
        else if (!vis[u])
            dfs(u);
    }
    vis[v] = 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        par[i] = i, sz[i] = 1;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        merge(u, v);
    }

    for (int i = 1; i <= n; ++i)
        cmp[find(i)].push_back(i);

    int ans = n;
    for (int i = 1; i <= n; ++i) {
        if (cmp[i].empty())
            continue;

        f = 0;
        for (int j : cmp[i])
            if (!vis[j])
                dfs(j);

        ans -= !f;
    }

    cout << ans << '\n';
}

