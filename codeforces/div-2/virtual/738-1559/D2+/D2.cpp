#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
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

    for (int c = 0; c < 2; ++c)
        for (int i = 1; i <= n; ++i)
            par[c][i] = i, sz[c][i] = 1;

    for (int c = 0; c < 2; ++c) {
        while (m[c]--) {
            int u, v;
            cin >> u >> v;
            merge(u, v, c);
        }
    }

    vector<array<int, 2>> ans;
    vector<int> v0, v1;
    for (int i = 2; i <= n; ++i) {
        if (!same_set(1, i, 0) && !same_set(1, i, 1)) {
            merge(1, i, 0);
            merge(1, i, 1);
            ans.push_back({1, i});
        } else if (same_set(1, i, 0)) {
            v0.push_back(i);
        } else if (same_set(1, i, 1)) {
            v1.push_back(i);
        }
    }

    int p0 = 0, p1 = 0;
    while (1) {
        while (p0 < v0.size() && same_set(1, v0[p0], 1))
            ++p0;
        while (p1 < v1.size() && same_set(1, v1[p1], 0))
            ++p1;

        if (p0 == v0.size() || p1 == v1.size())
            break;

        int u = v0[p0++], v = v1[p1++];
        ans.push_back({u, v});
        merge(u, v, 0);
        merge(u, v, 1);
    }

    cout << ans.size() << '\n';
    for (auto [u, v] : ans)
        cout << u << " " << v << '\n';
}


