#include <bits/stdc++.h>
using namespace std;

const int N = 469, MD = 998244353;
int n, m, dist[N][N];
vector<int> adj[N];

void bfs(int st) {
    queue<int> q;
    q.push(st);
    while (q.size()) {
        int v = q.front(); q.pop();
        for (int u : adj[v]) {
            if (dist[st][u] < 0) {
                dist[st][u] = dist[st][v] + 1;
                q.push(u);
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 1;
        bfs(i);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int on_path = 0, ret = 1;
            for (int k = 1; k <= n; ++k) {
                if (dist[i][j] == dist[i][k] + dist[k][j] - 1)
                    ++on_path;
                else {
                    int pos = 0;
                    for (int v : adj[k])
                        if (dist[i][k] == dist[i][v] + 1 && dist[j][k] == dist[j][v] + 1)
                            ++pos;

                    ret = 1LL * ret * pos % MD;
                }
            }

            if (on_path != dist[i][j])
                ret = 0;

            cout << ret << " \n"[j == n];
        }
    }
}
