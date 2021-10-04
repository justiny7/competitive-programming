#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 69;
int n, par[N];
vector<int> adj[N], tour;

int query(vector<int> nodes) {
    cout << "? " << nodes.size();
    for (int i : nodes)
        cout << " " << i;
    cout << endl;

    int ret;
    cin >> ret;
    return ret;
}

void dfs(int v = 1, int p = 0) {
    tour.push_back(v);
    par[v] = p;

    for (int u : adj[v])
        if (u != p)
            dfs(u, v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    int mx = query(tour);

    int lo = 1, hi = n - 1;
    while (lo < hi) {
        int m = lo + hi >> 1;

        vector<int> here;
        for (int i = 0; i <= m; ++i)
            here.push_back(tour[i]);

        int val = query(here);
        if (val == mx)
            hi = m;
        else
            lo = m + 1;
    }

    int x = tour[lo];
    cout << "! " << x << " " << par[x] << '\n';
}

