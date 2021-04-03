#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int n, t, ans, a[N], in[N], out[N], dp[N];
vector<int> adj[N];
map<int, vector<int>> mp;
set<pair<int, int>> s;

void dfs(int v = 1, int p = 0) { //Euler tour
    mp[a[v]].push_back(t);
    in[v] = t++;
    for (int u : adj[v])
        if (u != p)
            dfs(u, v);
    out[v] = t++;
}
void dfs2(int v = 1, int p = 0) { //Get directed edges
    auto &times = mp[a[v]];
    if (times.size() > 1) {
        int cur = 0;
        for (int u : adj[v]) {
            if (u == p)
                continue;
            int here = lower_bound(times.begin(), times.end(), out[u]) - lower_bound(times.begin(), times.end(), in[u]);
            if (here)
                s.emplace(v, u);
            cur += here;
        }
        if (times.size() > cur + 1)
            s.emplace(v, p);
    }
    for (int u : adj[v])
        if (u != p)
            dfs2(u, v);
}
void dfs3(int v = 1, int p = 0) { //Initial dp
    for (int u : adj[v]) {
        if (u != p) {
            dfs3(u, v);
            dp[v] += dp[u] + s.count({u, v});
        }
    }
}
void dfs4(int v = 1, int p = 0) { //Rerooting
    if (dp[v] == s.size())
        ++ans;
    for (int u : adj[v]) {
        if (u == p)
            continue;
        dp[v] -= dp[u] + s.count({u, v});
        dp[u] += dp[v] + s.count({v, u});
        dfs4(u, v);
        dp[u] -= dp[v] + s.count({v, u});
        dp[v] += dp[u] + s.count({u, v});
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    dfs(); dfs2(); dfs3(); dfs4();
    cout << ans << '\n';
}
