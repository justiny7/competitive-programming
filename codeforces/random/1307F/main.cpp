#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 69, L = 20;
int n, k, r, qu, t, dist[N], dep[N], lift[N][L];
vector<int> adj[N];

//DSU {{{
int par[N], sz[N];
int find(int v) {
    return (v == par[v] ? v : par[v] = find(par[v]));
}
bool merge(int u, int v) {
    if ((u = find(u)) == (v = find(v)))
        return 0;
    if (sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v], par[v] = u;
    return 1;
}
//}}}

void dfs(int v = 1, int p = 0, int d = 0) {
    dep[v] = d; lift[v][0] = p;
    for (int i = 1; i < L; ++i)
        lift[v][i] = lift[lift[v][i - 1]][i - 1];
    for (int u : adj[v]) {
        if (u == p)
            continue;
        if (~dist[u] && ~dist[v])
            merge(u, v);
        dfs(u, v, d + 1);
    }
}
int jump(int v, int x) {
    if (x >= dep[v])
        return 1;
    int ret = v;
    for (int i = L - 1; ~i; --i)
        if (x & (1 << i))
            ret = lift[ret][i];
    return ret;
}
int lca(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);
    u = jump(u, dep[u] - dep[v]);
    if (u == v)
        return u;
    for (int i = L - 1; ~i; --i)
        if (lift[u][i] != lift[v][i])
            u = lift[u][i], v = lift[v][i];
    return lift[u][0];
}

int main() {
    memset(dist, -1, sizeof(dist));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> r;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        int mid = n + i;
        adj[u].push_back(mid);
        adj[mid].push_back(u);
        adj[v].push_back(mid);
        adj[mid].push_back(v);
    }
    for (int i = 1; i <= n * 2; ++i)
        par[i] = i, sz[i] = 1;
    queue<int> q;
    for (int i = 0; i < r; ++i) {
        int x; cin >> x;
        dist[x] = 0;
        q.push(x);
    }
    while (q.size()) {
        int v = q.front(); q.pop();
        if (dist[v] == k)
            continue;
        for (int u : adj[v]) {
            if (dist[u] < 0) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
    dfs();
    cin >> qu;
    while (qu--) {
        int u, v, l;
        cin >> u >> v, l = lca(u, v);
        if (find(u) == find(v) || dep[u] + dep[v] - 2 * dep[l] <= k * 2)
            cout << "YES\n";
        else {
            if (dep[l] + k <= dep[v])
                v = jump(v, k);
            else
                v = jump(u, dep[v] + dep[u] - k - 2 * dep[l]);
            if (dep[l] + k <= dep[u])
                u = jump(u, k);
            else
                u = jump(v, dep[v] + dep[u] - k - 2 * dep[l]);
            cout << (find(u) == find(v) ? "YES" : "NO") << '\n';
        }
    }
}
