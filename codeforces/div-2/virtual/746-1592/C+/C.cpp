#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, k, tot, cnt, a[N], sub[N];
vector<int> adj[N];

void dfs(int v = 1, int p = 0) {
    sub[v] = a[v];

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            sub[v] ^= sub[u];
        }
    }

    if (sub[v] == tot) {
        sub[v] = 0;
        ++cnt;
    }
}

void solve() {
    cin >> n >> k;

    tot = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i], tot ^= a[i];
        sub[i] = 0;
        adj[i].clear();
    }

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cnt = 0;
    dfs();

    if (tot == 0 || (cnt > 2 && k > 2))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

