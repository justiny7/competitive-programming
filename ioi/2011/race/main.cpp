#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1, INF=1e9;
int k, ans=INF, sz[mxN];
vector<pair<int, int>> adj[mxN], vals;
map<int, int> mn;
bool vis[mxN];

int dfs_sz(int v, int p=-1) {
    sz[v]=1;
    for (auto [u, d]:adj[v])
        if (!vis[u] && u^p)
            sz[v]+=dfs_sz(u, v);
    return sz[v];
}
int dfs_centroid(int tot, int v, int p=-1) {
    for (auto [u, d]:adj[v])
        if (!vis[u] && u^p && sz[u]*2>tot)
            return dfs_centroid(tot, u, v);
    return v;
}
void dfs(int v, int len, int p=-1, int dep=1) {
    vals.emplace_back(dep, len);
    for (auto [u, d]:adj[v])
        if (!vis[u] && u^p && len+d<=k)
            dfs(u, len+d, v, dep+1);
}
void decomp(int x=0) {
    int v=dfs_centroid(dfs_sz(x), x);
    vis[v]=1;
    mn.clear();
    mn[0]=0;
    for (auto [u, d]:adj[v]) {
        if (vis[u])
            continue;
        vals.clear();
        dfs(u, d);
        for (auto [dep, len]:vals)
            if (mn.count(k-len))
                ans=min(ans, dep+mn[k-len]);
        for (auto [dep, len]:vals) {
            if (mn.count(len))
                mn[len]=min(mn[len], dep);
            else
                mn[len]=dep;
        }
    }
    for (auto [u, d]:adj[v])
        if (!vis[u])
            decomp(u);
}

int best_path(int N, int K, int H[][2], int L[]) {
    k=K;
    for (int i=0; i<N; ++i)
        adj[i].clear();
    for (int i=0; i<N-1; ++i) {
        adj[H[i][0]].emplace_back(H[i][1], L[i]);
        adj[H[i][1]].emplace_back(H[i][0], L[i]);
    }
    decomp();
    return (ans==INF?-1:ans);
}

