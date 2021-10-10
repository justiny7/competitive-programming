#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 69;
int n, m, c0, c1, vis[N];
vector<int> adj[N];
bool f;

void dfs(int v, int c = 0) {
    vis[v] = c;
    if (v <= n)
        (c ? c1 : c0)++;

    for (int u : adj[v]) {
        if (vis[u] < 0)
            dfs(u, c ^ 1);
        else if (vis[u] == c)
            f = 1;
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n + m; ++i)
        adj[i].clear();

    int o = n + 1;
    while (m--) {
        int u, v;
        string s;
        cin >> u >> v >> s;

        if (s[0] == 'c') { // u, v same team
            adj[u].push_back(o);
            adj[o].push_back(u);
            adj[o].push_back(v);
            adj[v].push_back(o);
            ++o;
        } else { // u, v diff team
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    f = 0;
    memset(vis, -1, sizeof(vis));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (vis[i] < 0) {
            c0 = c1 = 0;
            dfs(i);
            ans += max(c0, c1);
        }
    }

    if (f)
        cout << "-1\n";
    else
        cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

