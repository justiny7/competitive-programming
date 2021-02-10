#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1, mxL=20;
int n, m, ans[mxN], sz[mxN], par[mxN], dep[mxN], dp[mxN][mxL];
vector<int> adj[mxN];
bool vis[mxN];

void dfs(int v, int p=0) {
    sz[v]=1;
    for (int u:adj[v]) {
        if (!vis[u] && u^p) {
            dfs(u, v);
            sz[v]+=sz[u];
        }
    }
}
int centroid(int v) {
    dfs(v);
    int tot=sz[v], p=0;
    do {
        int nxt=0;
        for (int u:adj[v])
            if (!vis[u] && u^p && sz[u]*2>tot)
                nxt=u;
        p=v, v=nxt;
    } while (v);
    return p;
}
void decomp(int v=1, int p=0) {
    int c=centroid(v);
    vis[c]=1, par[c]=p;
    for (int u:adj[c])
        if (!vis[u])
            decomp(u, c);
}
void binlift(int v=1, int p=0, int d=0) {
    dp[v][0]=p, dep[v]=d;
    for (int i=1; i<mxL; ++i)
        dp[v][i]=dp[dp[v][i-1]][i-1];
    for (int u:adj[v])
        if (u^p)
            binlift(u, v, d+1);
}
int lca(int a, int b) {
    if (dep[a]<dep[b])
        swap(a, b);
    for (int i=mxL-1; ~i; --i)
        if (dep[a]>=dep[b]+(1<<i))
            a=dp[a][i];
    if (a==b)
        return a;
    for (int i=mxL-1; ~i; --i)
        if (dp[a][i]^dp[b][i])
            a=dp[a][i], b=dp[b][i];
    return dp[a][0];
}
int dist(int a, int b) {
    return (dep[a]+dep[b]-2*dep[lca(a, b)]);
}

void upd(int x) {
    int v=x;
    while (v) {
        ans[v]=min(ans[v], dist(v, x));
        v=par[v];
    }
}
int query(int x) {
    int v=x, ret=INT_MAX;
    while (v) {
        ret=min(ret, ans[v]+dist(v, x));
        v=par[v];
    }
    return ret;
}

int main() {
    memset(ans, 0x3f, sizeof(ans));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    decomp();
    binlift();
    upd(1);
    while (m--) {
        int t, v;
        cin >> t >> v;
        if (t&1)
            upd(v);
        else
            cout << query(v) << '\n';
    }
}

