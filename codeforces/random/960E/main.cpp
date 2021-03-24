#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Formula: (# of new)(Sum of old) + (# of old)(Sum of new)
// Sum of old includes root, Sum of new excludes root

const int mxN = 2e5 + 1;
const ll M = 1e9 + 7;
int n, sz[mxN];
ll ans, val[mxN], sum[2], cnt[2];
vector<int> adj[mxN];
bool vis[mxN];

int dfs_sz(int v, int p = 0) {
    sz[v] = 1;
    for (int u : adj[v])
        if (!vis[u] && u != p)
            sz[v] += dfs_sz(u, v);
    return sz[v];
}
int dfs_centroid(int tot, int v, int p = 0) {
    for (int u : adj[v])
        if (!vis[u] && u != p && sz[u] * 2 > tot)
            return dfs_centroid(tot, u, v);
    return v;
}
array<ll, 4> dfs(int v, ll cur, int p = 0, int dep = 1) {
    array<ll, 4> here = {0, 0, 0, 0};
    here[dep * 2] = cur;
    here[dep * 2 + 1] = 1;
    for (int u : adj[v]) {
        if (vis[u] || u == p)
            continue;
        auto there = dfs(u, (cur + (val[u] * (dep ? 1 : -1))) % M, v, dep ^ 1);
        for (int i = 0; i < 4; ++i)
            (here[i] += there[i]) %= M;
    }
    return here;
}
void decomp(int x = 1) {
    int v = dfs_centroid(dfs_sz(x), x);
    vis[v] = 1;
    sum[0] = val[v], cnt[0] = 1;
    sum[1] = cnt[1] = 0;
    for (int u : adj[v]) {
        if (vis[u])
            continue;
        auto [esum, ecnt, osum, ocnt] = dfs(u, -val[u]);
        (ans += 2 * (ecnt * sum[0] % M + cnt[0] * esum % M) % M) %= M;
        (ans -= 2 * (ocnt * sum[1] % M + cnt[1] * osum % M) % M) %= M;
        (sum[0] += esum + val[v] * ecnt % M) %= M, (cnt[0] += ecnt) %= M;
        (sum[1] += osum + val[v] * ocnt % M) %= M, (cnt[1] += ocnt) %= M;
        if (ans < 0)
            ans += M;
    }
    for (int u : adj[v])
        if (!vis[u])
            decomp(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> val[i], ans += val[i];
    for (int i = 1; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    decomp();
    cout << ans << '\n';
}
