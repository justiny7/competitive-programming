#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 69;
int n, k, dist[N];
set<int> adj[N];

void solve() {
    cin >> n >> k;
    
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        dist[i] = -1;
    }

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() == 1) {
            dist[i] = 1;
            q.push(i);
        }
    }

    while (q.size()) {
        int v = q.front();
        q.pop();

        if (adj[v].size() == 0) {
            assert(q.empty());
            break;
        }

        int p = *adj[v].begin();

        adj[v].erase(p);
        adj[p].erase(v);
        if (adj[p].size() == 1) {
            dist[p] = dist[v] + 1;
            q.push(p);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++i)
        res += dist[i] > k;

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

