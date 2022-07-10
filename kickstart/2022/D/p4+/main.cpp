#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, m, k;
vector<int> adj[N];
set<int> vis;

void dfs(int v, int p) {
    if (vis.size() > k - 1)
        return;

    for (int u : adj[v]) {
        if (u != p && !vis.count(u)) {
            vis.insert(u);
            dfs(u, p);
        }
    }
}

void solve() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i)
        adj[i].clear();

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[v].push_back(u);
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        vis.clear();
        dfs(i, i);

        if (vis.size() > k - 1)
            ++res;
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

