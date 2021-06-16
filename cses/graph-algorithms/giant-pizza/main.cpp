#include <bits/stdc++.h>
using namespace std;

// 2-SAT {{{
struct Two_Sat {
    int sz, tt = 0;
    vector<vector<int>> adj;
    vector<int> res, val, scc, z;

    Two_Sat() {}
    Two_Sat(int _sz) { init(_sz); }
    void init(int _sz = 0) {
        sz = _sz;
        adj.resize(sz * 2);
    }

    void either(int f, int j) {
        f = max(f * 2, -1 - f * 2);
        j = max(j * 2, -1 - j * 2);
        adj[f].push_back(j ^ 1);
        adj[j].push_back(f ^ 1);
    }
    int dfs(int v) {
        int low = val[v] = ++tt, x;
        z.push_back(v);
        for (int u : adj[v])
            if (!scc[u])
                low = min(low, val[u] ? : dfs(u));

        if (low == val[v]) {
            do {
                x = z.back(); z.pop_back();
                scc[x] = low;
                if (res[x >> 1] < 0)
                    res[x >> 1] = x & 1;
            } while (x != v);
        }

        return val[v] = low;
    }
    bool solve() {
        res.assign(sz, -1);
        val.assign(sz * 2, 0);
        scc.assign(sz * 2, 0);

        for (int i = 0; i < sz * 2; ++i)
            if (!scc[i])
                dfs(i);

        for (int i = 0; i < sz; ++i)
            if (scc[i * 2] == scc[i * 2 + 1])
                return 0;

        return 1;
    }
};
// }}}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    Two_Sat g(m);

    while (n--) {
        int u, v; char cu, cv;
        cin >> cu >> u >> cv >> v;
        --u, --v;

        if (cu == '-')
            u = ~u;
        if (cv == '-')
            v = ~v;

        g.either(u, v);
    }

    if (g.solve()) {
        for (int i = 0; i < m; ++i)
            cout << (g.res[i] ? '+' : '-') << " \n"[i == m - 1];
    }
    else
        cout << "IMPOSSIBLE\n";
}
