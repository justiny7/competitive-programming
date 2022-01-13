#include <bits/stdc++.h>
using namespace std;

// DSU {{{
struct DSU {
    vector<int> dsu;
    void init(int n) {
        dsu.assign(n, -1);
    }
    
    int find(int v) {
        return dsu[v] < 0 ? v : dsu[v] = find(dsu[v]);
    }
    int size(int v) {
        return -dsu[find(v)];
    }
    bool merge(int u, int v) {
        if ((u = find(u)) == (v = find(v)))
            return 0;
        if (dsu[u] < dsu[v])
            swap(u, v);
        dsu[v] += dsu[u], dsu[u] = v;
        return 1;
    }
    bool same_set(int u, int v) {
        return find(u) == find(v);
    }
};
// }}}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> edges;
    while (m--) {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({u, v, c});
    }

    int res = (1 << 30) - 1;
    for (int bit = 29; ~bit; --bit) {
        DSU d;
        d.init(n + 69);

        res ^= (1 << bit);
        for (auto [u, v, c] : edges)
            if ((res & c) == c)
                d.merge(u, v);

        bool f = 1;
        for (int i = 1; i <= n; ++i)
            f &= d.same_set(1, i);

        if (!f)
            res ^= (1 << bit);
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

