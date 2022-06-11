#include <bits/stdc++.h>
using namespace std;

const int N = 4e3 + 69;
int n, col[N], sz[N], sub[N];
vector<int> adj[N];

void dfs(int v = 1) {
    for (int u : adj[v]) {
        dfs(u);
        sz[v] += sz[u];
        sub[v] += sub[u];
    }
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        sz[i] = sub[i] = 0;
        adj[i].clear();
    }

    for (int i = 2; i <= n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
    }

    for (int i = 1; i <= n; ++i) {
        char c;
        cin >> c;
        sub[i] = c == 'W';
        sz[i] = 1;
    }

    dfs();

    int res = 0;
    for (int i = 1; i <= n; ++i)
        res += (sub[i] * 2 == sz[i]);

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}


