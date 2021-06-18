#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 69;
int n, m, col[N];
ll have[N], need[N];
vector<int> adj[N];

bool dfs(int v = 1) {
    for (int u : adj[v]) {
        if (col[u] < 0) {
            col[u] = col[v] ^ 1;
            if (!dfs(u))
                return 0;
        }
        else if (col[u] == col[v])
            return 0;
    }

    return 1;
}

void solve() {
    cin >> n >> m;

    ll hs = 0, ns = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> have[i];
        hs += abs(have[i]);

        adj[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        cin >> need[i];
        ns += abs(need[i]);
    }

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if ((ns & 1) != (hs & 1)) {
        cout << "NO\n";
        return;
    }

    fill(col + 1, col + n + 1, -1);
    col[1] = 0;
    if (dfs()) {
        ll s = 0;
        for (int i = 1; i <= n; ++i)
            s += (need[i] - have[i]) * (col[i] ? 1 : -1);

        cout << (s == 0 ? "YES" : "NO") << '\n';
    }
    else
        cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--)
        solve();
}
