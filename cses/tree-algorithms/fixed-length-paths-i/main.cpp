#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
int n, k, mx;
ll ans, sz[mxN], cnt[mxN];
vector<int> adj[mxN];
bool vis[mxN];

ll dfs_sz(int v, int p=0) {
    sz[v]=1;
    for (int u:adj[v])
        if (!vis[u] && u^p)
            sz[v]+=dfs_sz(u, v);
    return sz[v];
}
int dfs_centroid(ll tot, int v, int p=0) {
    for (int u:adj[v])
        if (!vis[u] && u^p && sz[u]*2>tot)
            return dfs_centroid(tot, u, v);
    return v;
}
void dfs_cnt(int v, int p, bool f, int d=1) {
    if (d>k)
        return;
    mx=max(mx, d);
    (f)?ans+=cnt[k-d]:++cnt[d];
    for (int u:adj[v])
        if (!vis[u] && u^p)
            dfs_cnt(u, v, f, d+1);
}
void decomp(int v=1) {
    int c=dfs_centroid(dfs_sz(v), v);
    vis[c]=1, mx=0;
    for (int u:adj[c]) {
        if (vis[u])
            continue;
        dfs_cnt(u, c, 1);
        dfs_cnt(u, c, 0);
    }
    fill(cnt+1, cnt+mx+1, 0);
    for (int u:adj[c])
        if (!vis[u])
            decomp(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cnt[0]=1;
    decomp();
    cout << ans << '\n';
}

