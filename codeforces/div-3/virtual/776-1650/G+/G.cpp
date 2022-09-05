#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 69, MOD = 1e9 + 7;
int n, m, s, t;
int dist[N];
ll res[N][2];
vector<int> adj[N];

void solve() {
    cin >> n >> m >> s >> t;

    for (int i = 1; i <= n; ++i) {
        dist[i] = -10;
        adj[i].clear();
        res[i][0] = res[i][1] = 0;
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    q.push(s);
    res[s][0] = 1;
    dist[s] = 0;
    while (q.size()) {
        int v = q.front();
        q.pop();

        for (int u : adj[v]) {
            if (dist[u] < 0) {
                dist[u] = dist[v] + 1;
                q.push(u);
            }

            if (dist[u] == dist[v] + 1)
                (res[u][0] += res[v][0]) %= MOD;
            if (dist[u] == dist[v])
                (res[u][1] += res[v][0]) %= MOD;
            if (dist[u] == dist[v] - 1)
                (res[v][1] += res[u][1]) %= MOD;
        }
    }

    cout << (res[t][0] + res[t][1]) % MOD << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

