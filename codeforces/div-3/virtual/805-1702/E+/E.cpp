#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, a[N], b[N], col[N];
vector<int> adj[N];
bool bipartite;

void dfs(int v, int c = 0) {
    col[v] = c;

    for (int u : adj[v]) {
        if (col[u] < 0)
            dfs(u, c ^ 1);
        else if (col[u] == c)
            bipartite = 0;
    }
}

void solve() {
    cin >> n;

    vector<vector<int>> pos(n + 1);

    bool f = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];

        pos[a[i]].push_back(i);
        pos[b[i]].push_back(i);

        col[i] = -1;
        adj[i].clear();
    }

    for (int i = 1; i <= n; ++i) {
        if (pos[i].size() > 2) {
            cout << "NO\n";
            return;
        }

        if (pos[i].size() == 2) {
            adj[pos[i][0]].push_back(pos[i][1]);
            adj[pos[i][1]].push_back(pos[i][0]);
        }
    }

    bipartite = 1;
    for (int i = 0; i < n; ++i)
        if (col[i] < 0)
            dfs(i);

    cout << (bipartite ? "YES" : "NO") << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

