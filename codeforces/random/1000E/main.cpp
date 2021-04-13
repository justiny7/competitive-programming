#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 69;
int n, m, ans, t, in[N], out[N], low[N], dp[N];
vector<int> adj[N];
vector<pair<int, int>> tadj[N];
bool vis[N];

void dfs(int v = 1, int p = 0) {
    vis[v] = 1;
    in[v] = low[v] = t++;
    for (int u : adj[v]) {
        if (u == p)
            continue;
        if (vis[u])
            low[v] = min(low[v], in[u]);
        else {
            dfs(u, v);
            low[v] = min(low[v], low[u]);
            int w = 0;
            if (low[u] > in[v])
                w = 1;
            tadj[v].emplace_back(u, w);
        }
    }
}
void dfs2(int v = 1) {
    vector<int> here;
    for (auto [u, w] : tadj[v]) {
        dfs2(u);
        here.push_back(dp[u] + w);
    }
    if (here.empty())
        return;
    sort(here.begin(), here.end());
    dp[v] = here.back();
    int ret = here.back();
    if (here.size() > 1)
        ret += here[here.size() - 2];
    ans = max(ret, ans);
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
    dfs(); dfs2();
    cout << ans << '\n';
}
