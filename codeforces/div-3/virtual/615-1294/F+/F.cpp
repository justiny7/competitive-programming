#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, par[N], dist[N];
array<int, 3> diam;
vector<int> adj[N];

void dfs(int v, int c, int p = 0, int d = 0) {
    par[v] = p;

    if (d > diam[2])
        diam[c] = v, diam[2] = d;

    for (int u : adj[v])
        if (u != p)
            dfs(u, c, v, d + 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);
    diam[2] = -1;
    dfs(diam[0], 1);

    // cout << diam[0] << " " << diam[1] << " " << diam[2] << '\n';

    queue<int> q;
    memset(dist, -1, sizeof(dist));

    q.push(diam[1]);
    dist[diam[1]] = 0;
    for (int v = diam[1]; v != diam[0]; v = par[v]) {
        q.push(v);
        dist[v] = 0;
    }

    while (q.size()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (dist[u] < 0) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    int mx = -1, res;
    for (int i = 1; i <= n; ++i) {
        if (dist[i] > mx && i != diam[0] && i != diam[1]) {
            mx = dist[i];
            res = i;
        }
    }

    cout << diam[2] + mx << '\n';
    cout << diam[0] << " " << diam[1] << " " << res << '\n';
}

