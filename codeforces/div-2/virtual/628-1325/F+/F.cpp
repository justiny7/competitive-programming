#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, m, targ, cnt[N], par[N];
vector<int> adj[N], s;
bool vis[N];

void dfs(int v = 1, int p = 0, int d = 1) {
    par[v] = p;
    cnt[v] = d;

    for (int u : adj[v]) {
        if (!cnt[u])
            dfs(u, v, d + 1);
        else if (cnt[v] - cnt[u] + 1 >= targ) { // >= targ nodes between this node and previous node
            int k = cnt[v] - cnt[u] + 1;
            cout << "2\n" << k << '\n';

            while (k--) {
                cout << v << " \n"[k == 0];
                v = par[v];
            }

            exit(0);
        }
    }

    if (!vis[v]) { // blocks out < targ nodes from independent set?
        s.push_back(v);
        for (int u : adj[v])
            vis[u] = 1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    targ = ceil(sqrt(n));
    dfs();

    while (s.size() > targ)
        s.pop_back();

    cout << "1\n";
    for (int i = 0; i < targ; ++i)
        cout << s[i] << " \n"[i == targ - 1];
}
