#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, m, st, vis[N], par[N][2];
vector<int> adj[N], snk;

void dfs(int v, int c = 0, int p = 0) {
    par[v][c] = p;
    for (int u : adj[v])
        if (par[u][c ^ 1] < 0)
            dfs(u, c ^ 1, v);
}
bool dfs_cyc(int v) {
    vis[v] = 1;

    for (int u : adj[v])
        if (vis[u] == 1 || (!vis[u] && dfs_cyc(u)))
            return 1;

    vis[v] = 2;
    return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int k; cin >> k;

        if (!k)
            snk.push_back(i);

        while (k--) {
            int u; cin >> u;
            adj[i].push_back(u);
        }
    }

    memset(par, -1, sizeof(par));
    cin >> st;
    dfs(st);

    int en = -1;
    for (int v : snk)
        if (~par[v][1])
            en = v;

    if (~en) {
        cout << "Win\n";

        vector<int> ans;
        int c = 0;
        while (en > 0) {
            ans.push_back(en);
            en = par[en][c ^= 1];
        }

        for (int i = ans.size() - 1; ~i; --i)
            cout << ans[i] << " \n"[i == 0];
    }
    else if (dfs_cyc(st))
        cout << "Draw\n";
    else
        cout << "Lose\n";
}
