#include <bits/stdc++.h>
using namespace std;

const int mxN = 5e3 + 1;
int n, m, col[mxN][mxN], par[mxN];
vector<int> adj[mxN];
pair<int, int> edges[mxN];
array<int, 3> qu[mxN];

void dfs(int v, int p = 0) {
    par[v] = p;
    for (int u : adj[v])
        if (u != p)
            dfs(u, v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edges[i] = {a, b};
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> qu[i][1] >> qu[i][2] >> qu[i][0];
    sort(qu, qu + m);
    for (int i = 0; i < m; ++i) {
        auto [x, st, en] = qu[i];
        dfs(st);
        int v = en;
        while (v != st) {
            col[v][par[v]] = col[par[v]][v] = x;
            v = par[v];
        }
    }
    bool f = 0;
    for (int i = 0; i < m; ++i) {
        auto [x, st, en] = qu[i];
        dfs(st);
        int v = en, mn = INT_MAX;
        while (v != st) {
            mn = min(mn, col[v][par[v]]);
            v = par[v];
        }
        if (mn != x)
            f = 1;
    }
    if (f)
        cout << "-1\n";
    else {
        for (int i = 0; i < n - 1; ++i) {
            auto [a, b] = edges[i];
            if (!col[a][b])
                col[a][b] = 1;
            cout << col[a][b] << " \n"[i == n - 2];
        }
    }
}
