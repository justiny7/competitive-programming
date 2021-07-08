#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class t> using oset = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

const int N = 1e5 + 69;
int n, m, a[N], ans[N];
vector<int> adj[N];
vector<array<int, 2>> qu[N];
map<int, int> occ[N];
oset<array<int, 2>> cnts[N];

void dfs(int v = 1, int p = 0) {
    ++occ[v][a[v]];
    cnts[v].insert({1, a[v]});

    for (int u : adj[v]) {
        if (u == p)
            continue;

        dfs(u, v);

        if (occ[v].size() < occ[u].size()) {
            occ[v].swap(occ[u]);
            cnts[v].swap(cnts[u]);
        }

        for (auto [k, c] : occ[u]) {
            if (occ[v].count(k))
                cnts[v].erase({occ[v][k], k});

            occ[v][k] += c;
            cnts[v].insert({occ[v][k], k});
        }

        occ[u].clear();
        cnts[u].clear();
    }

    for (auto [u, i] : qu[v])
        ans[i] = cnts[v].size() - cnts[v].order_of_key({u, -1});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < m; ++i) {
        int x, k;
        cin >> x >> k;
        qu[x].push_back({k, i});
    }

    dfs();

    for (int i = 0; i < m; ++i)
        cout << ans[i] << '\n';
}
