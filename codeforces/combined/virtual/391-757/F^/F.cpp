#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 69, L = 20;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, s, lift[N][L], dep[N], sz[N];
ll dist[N];
vector<pair<ll, ll>> adj[N], topo;
vector<int> tadj[N], radj[N], dadj[N];

int lca(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);
    //cout << "! " << u << " " << v << '\n';
    int dif = dep[u] - dep[v];
    for (int i = L - 1; ~i; --i)
        if (dif & (1 << i))
            u = lift[u][i];
    //cout << "! " << u << " " << v << '\n';
    if (u == v)
        return u;
    for (int i = L - 1; ~i; --i)
        if (lift[u][i] != lift[v][i])
            u = lift[u][i], v = lift[v][i];
    return lift[u][0];
}
void dfs(int v = s, int p = 0) {
    sz[v] = 1;
    for (int u : dadj[v])
        if (u != p)
            dfs(u, v), sz[v] += sz[u];
}

int main() {
    memset(dist, 0x3f, sizeof(dist));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s;
    while (m--) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[v].emplace_back(u, w);
        adj[u].emplace_back(v, w);
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
    pq.emplace(0, s);
    dist[s] = 0;
    while (pq.size()) {
        auto [d, v] = pq.top(); pq.pop();
        if (dist[v] < d)
            continue;
        for (auto [u, w] : adj[v]) {
            if (dist[u] > d + w) {
                dist[u] = d + w;
                pq.emplace(dist[u], u);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        //cout << i << " " << dist[i] << '\n';
        if (dist[i] == INF)
            continue;
        topo.emplace_back(dist[i], i);
        for (auto [u, w] : adj[i]) {
            if (dist[u] == dist[i] + w) {
                //cout << "edge going from " << u << " to " << i << '\n';
                tadj[i].push_back(u);
                radj[u].push_back(i);
            }
        }
    }
    sort(topo.begin(), topo.end());
    //for (int i : topo)
    //cout << i << " "; cout << '\n';
    for (int i = 0; i < topo.size(); ++i) {
        int v = topo[i].second;
        if (dist[v] == INF)
            continue;
        if (radj[v].empty()) {
            assert(v == s);
            dep[v] = 0;
            for (int l = 1; l < L; ++l)
                lift[v][l] = lift[lift[v][l - 1]][l - 1];
        }
        else {
            int p = radj[v][0];
            for (int i = 1; i < radj[v].size(); ++i)
                p = lca(p, radj[v][i]);
            lift[v][0] = p;
            dep[v] = dep[p] + 1;
            for (int l = 1; l < L; ++l)
                lift[v][l] = lift[lift[v][l - 1]][l - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF || i == s)
            continue;
        //cout << i << " " << lift[i][0] << '\n';
        dadj[lift[i][0]].push_back(i);
    }
    dfs();
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        if (i != s && dist[i] != INF)
            ans = max(ans, sz[i]);
    cout << ans << '\n';
}
