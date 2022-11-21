#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, a, b;
set<int> val;
vector<array<int, 2>> adj[N];
bool res = 0;

void dfs_b(int v = b, int p = 0, int q = 0) {
    if (p)
        val.insert(q);

    for (auto [u, c] : adj[v])
        if (u != p)
            dfs_b(u, v, q ^ c);
}
void dfs_a(int v = a, int p = 0, int q = 0) {
    if (v == b) {
        res |= (q == 0);
        return;
    }

    res |= val.count(q);

    for (auto [u, c] : adj[v])
        if (u != p)
            dfs_a(u, v, q ^ c);
}

void solve() {
    cin >> n >> a >> b;
    
    val.clear();
    for (int i = 1; i <= n; ++i)
        adj[i].clear();

    for (int i = 1, u, v, c; i < n; ++i) {
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    res = 0;
    dfs_b();
    dfs_a();

    cout << (res ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

