#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, k, deg[N], dist[N];
vector<pair<int, int>> adj[N];
bool vis[N];

bool ok(int x) {
    int tot = 0, have = n;
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        deg[i] = adj[i].size(), dist[i] = vis[i] = 0;
        tot += (deg[i] > 2);
        if (deg[i] == 1)
            q.push(i);
    }

    while (q.size()) {
        int v = q.front(); q.pop();
        pair<int, int> take;
        for (auto [u, w] : adj[v]) {
            if (!vis[u]) {
                take = {u, w};
                break;
            }
        }

        if (dist[v] + take.second > x)
            continue;

        int u = take.first;
        vis[v] = 1;
        dist[u] = max(dist[u], dist[v] + take.second);
        --deg[u];
        --have;
        if (deg[u] == 2)
            --tot;
        else if (deg[u] == 1)
            q.push(u);
    }
    return (tot == 0 && have <= k);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1, u, v, w; i < n; ++i) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    int lo = 0, hi = 1e9;
    while (lo < hi) {
        int m = lo + hi >> 1;
        if (ok(m))
            hi = m;
        else
            lo = m + 1;
    }

    cout << lo << '\n';
}
