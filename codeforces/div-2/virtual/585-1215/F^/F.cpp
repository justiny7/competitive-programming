#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 69;
int n, p, mx, m;

//2-SAT {{{
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
//}}}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> p >> mx >> m;
    Two_Sat g(p + mx - 1);
    for (int i = 2; i < mx; ++i) {
        int u = p + i - 2, v = u + 1;
        g.either(u, ~v);
    }
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        g.either(u, v);
    }
    for (int i = 0; i < p; ++i) {
        int l, r;
        cin >> l >> r;
        if (l > 1)
            g.either(p + l - 2, ~i);
        if (r < mx)
            g.either(~(p + r - 1), ~i);
    }
    while (m--) {
        int u, v;
        cin >> u >> v, --u, --v;
        g.either(~u, ~v);
    }
    if (g.solve()) {
        vector<int> ans; int ret = 1, sz = 0;
        for (int i = 0; i < p + mx - 1; ++i) {
            if (!g.res[i])
                continue;
            if (i < p)
                ans.push_back(i + 1), ++sz;
            else
                ret = max(ret, i - p + 2);
        }
        cout << sz << " " << ret << '\n';
        for (int i = 0; i < sz; ++i)
            cout << ans[i] << " \n"[i == sz - 1];
    }
    else
        cout << "-1\n";
}
