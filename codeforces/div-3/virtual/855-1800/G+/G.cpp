#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;

struct Graph {
    int n, id;
    vector<int> shape;
    vector<vector<int>> adj;
    map<vector<int>, int> mp;

    void init(int _n) {
        id = 0;
        n = _n;
        shape.resize(n);
        adj.resize(n);
    }
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int dfs(int v = 1, int p = 0) {
        vector<int> cur;
        for (int u : adj[v])
            if (u != p)
                cur.push_back(dfs(u, v));

        sort(cur.begin(), cur.end());
        return shape[v] = (mp.count(cur) ? mp[cur] : mp[cur] = id++);
    }
    bool check(int v = 1, int p = 0) {
        map<int, int> here;
        for (int u : adj[v])
            if (u != p)
                ++here[shape[u]];

        int o = -1;
        for (auto [x, c] : here) {
            if (c & 1) {
                if (~o)
                    return 0;
                o = x;
            }
        }

        // cout << "> " << v << " " << o << '\n';

        if (~o) {
            for (int u : adj[v])
                if (u != p && o == shape[u])
                    return check(u, v);
            assert(false);
        } else {
            return 1;
        }
        assert(false);
    }
    void go() {
        dfs();
        if (check())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
};

void solve() {
    int n;
    cin >> n;

    Graph g;
    g.init(n + 1);

    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        g.add_edge(u, v);
    }

    g.go();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

