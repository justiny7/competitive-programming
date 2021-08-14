#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 69;
int n, m, ans, col[N], dist[N];
vector<int> adj[N];
vector<vector<int>> cmps;
bool bipartite = 1;

void dfs(int v) {
    cmps.back().push_back(v);

    for (int u : adj[v]) {
        if (col[u] < 0) {
            col[u] = col[v] ^ 1;
            dfs(u);
        } else if (col[u] == col[v]) {
            bipartite = 0;
        }
    }
}
int bfs(vector<int> &cmp) {
    int ret = 0;

    for (int st : cmp) {
        memset(dist, -1, sizeof(dist));
        queue<int> q;

        dist[st] = 0;
        q.push(st);
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

        ret = max(ret, *max_element(dist + 1, dist + n + 1));
    }

    return ret;
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

    memset(col, -1, sizeof(col));
    for (int i = 1; i <= n; ++i) {
        if (col[i] < 0) {
            col[i] = 0;
            cmps.push_back({});
            dfs(i);
        }
    }

    if (!bipartite) {
        cout << "-1\n";
        return 0;
    }

    for (vector<int> &cmp : cmps)
        ans += bfs(cmp);

    cout << ans << '\n';
}

