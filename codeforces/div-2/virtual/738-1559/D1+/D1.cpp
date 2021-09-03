#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 69;
int n, m[2], col[2][N];
vector<int> adj[2][N];

// DSU {{{
int par[2][N], sz[2][N];

int find(int v, int c) {
    return v == par[c][v] ? v : par[c][v] = find(par[c][v], c);
}
bool same_set(int u, int v, int c) {
    return find(u, c) == find(v, c);
}
bool merge(int u, int v, int c) {
    if ((u = find(u, c)) == (v = find(v, c)))
        return 0;
    if (sz[c][u] > sz[c][v])
        swap(u, v);
    par[c][u] = v, sz[c][v] += sz[c][u];
    return 1;
}
// }}}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m[0] >> m[1];

    for (int c = 0; c < 2; ++c) {
        while (m[c]--) {
            int u, v;
            cin >> u >> v;
            adj[c][u].push_back(v);
            adj[c][v].push_back(u);
        }
    }

    for (int c = 0; c < 2; ++c)
        for (int i = 1; i <= n; ++i)
            par[c][i] = i, sz[c][i] = 1;

    for (int c = 0; c < 2; ++c) {
        int cur = 1;
        for (int i = 1; i <= n; ++i)
            for (int u : adj[c][i])
                merge(i, u, c);
    }


    vector<array<int, 2>> ans;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (!same_set(i, j, 0) && !same_set(i, j, 1)) {
                merge(i, j, 0);
                merge(i, j, 1);
                ans.push_back({i, j});
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto [u, v] : ans)
        cout << u << " " << v << '\n';
}

