#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, m, par[N], vis[N];
vector<int> adj[N], ans;

void dfs(int v, int p = 0) {
    vis[v] = 1, par[v] = p;
    for (int u : adj[v]) {
        if (!vis[u])
            dfs(u, v);
        else if (vis[u] == 1) {
            ans.push_back(u);
            while (v != u) {
                ans.push_back(v);
                v = par[v];
            }
            ans.push_back(u);
            cout << ans.size() << '\n';
            for (int i = ans.size() - 1; ~i; --i)
                cout << ans[i] << " \n"[i == 0];
            exit(0);
        }
    }
    vis[v] = 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i);
    cout << "IMPOSSIBLE\n";
}
