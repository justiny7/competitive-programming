#include <bits/stdc++.h>
using namespace std;

// SCCs {{{
struct SCC {
    // cmps holds the components in topological order
    // tadj holds the compressed DAG
    int sz, tt = 0;
    vector<int> tin, comp, st, cmps;
    vector<vector<int>> adj, tadj, vals;
    void init(int _sz) {
        sz = _sz;
        adj.resize(sz), tadj.resize(sz), vals.resize(sz);
        tin.assign(sz, 0), comp.assign(sz, -1);
    }

    void add_edge(int u, int v) {
        adj[u].push_back(v);
    }
    int dfs(int v) {
        int low = tin[v] = ++tt;
        st.push_back(v);

        for (int u : adj[v])
            if (comp[u] < 0)
                low = min(low, tin[u] ? : dfs(u));

        if (low == tin[v]) {
            cmps.push_back(v);
            for (int u = -1; u != v; )
                comp[u = st.back()] = v, st.pop_back();
        }

        return low;
    }
    void go() {
        for (int i = 0; i < sz; ++i)
            if (!tin[i])
                dfs(i);

        for (int i = 0; i < sz; ++i) {
            vals[comp[i]].push_back(i);
            for (int u : adj[i])
                if (comp[i] != comp[u])
                    tadj[comp[i]].push_back(comp[u]);
        }

        reverse(cmps.begin(), cmps.end());
    }
};
// }}}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    SCC g;
    g.init(n);

    for (int t = 0; t < 2; ++t) {
        for (int i = 0, lst = -1; i < n; ++i) {
            if (lst < 0)
                cin >> lst, --lst;
            else {
                int x;
                cin >> x, --x;
                g.add_edge(lst, x);
                lst = x;
            }
        }
    }

    g.go();

    if (g.cmps.size() < k)
        cout << "NO\n";
    else {
        cout << "YES\n";

        string res(n, '$');
        char cur = 'a';
        for (int cmp : g.cmps) {
            for (int pos : g.vals[cmp])
                res[pos] = cur;
            if ((cur - 'a') + 1 < k)
                ++cur;
        }
        cout << res << '\n';
    }
}

