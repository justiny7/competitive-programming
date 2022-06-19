#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, mk[N];
vector<int> adj[N];

void dfs_prep(int v, int p = 0) {
    if (adj[v].size() == 1)
        mk[v] = 1;

    int ch = -1;
    for (int u : adj[v]) {
        if (u != p) {
            ch = u;
            dfs_prep(u, v);
        }
    }

    if (adj[v].size() == 2 && mk[ch])
        mk[v] = 1;
}
int dfs_res(int v, int p = 0) {
    int here = 0, leaf = 0;

    for (int u : adj[v]) {
        if (u == p)
            continue;
        if (mk[u])
            ++leaf;
        else
            here += dfs_res(u, v);
    }

    return here + max(0, leaf - 1);
}

void solve() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        mk[i] = 0;
        adj[i].clear();
    }

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 1) {
        cout << "0\n";
        return;
    }

    bool line = 1;
    for (int i = 1; i <= n; ++i)
        line &= (adj[i].size() <= 2);

    if (line) {
        cout << "1\n";
        return;
    }


    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() > 2) {
            dfs_prep(i);
            cout << dfs_res(i) << '\n';
            return;
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

