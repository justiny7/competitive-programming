#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+5;
int n, lo, hi, mx, sz[mxN];
ll ans, bit[mxN];
vector<int> adj[mxN];
bool vis[mxN];

void upd(int i, ll x) {
    for (++i; i<mxN; i+=i&-i)
        bit[i]+=x;
}
ll query(int i) {
    ll ret=0;
    for (++i; i; i-=i&-i)
        ret+=bit[i];
    return ret;
}
ll query(int l, int r) {
    return query(r)-query(l-1);
}
int dfs(int v, int p=0) {
    sz[v]=1;
    for (int u:adj[v])
        if (!vis[u] && u^p)
            sz[v]+=dfs(u, v);
    return sz[v];
}
int centroid(int tot, int v, int p=0) {
    for (int u:adj[v])
        if (!vis[u] && u^p && sz[u]*2>tot)
            return centroid(tot, u, v);
    return v;
}
void dfs2(int v, int p, bool f, int d=1) {
    if (d>hi)
        return;
    mx=max(mx, d);
    if (f)
        ans+=query(max(lo-d, 0), hi-d);
    else
        upd(d, 1);
    for (int u:adj[v])
        if (!vis[u] && u^p)
            dfs2(u, v, f, d+1);
}
void decomp(int x=1) {
    int v=centroid(dfs(x), x);
    vis[v]=1, mx=0;
    for (int u:adj[v]) {
        if (vis[u])
            continue;
        dfs2(u, v, 1);
        dfs2(u, v, 0);
    }
    for (int i=1; i<=mx; ++i)
        upd(i, -query(i, i));
    for (int u:adj[v])
        if (!vis[u])
            decomp(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> lo >> hi;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    upd(0, 1);
    decomp();
    cout << ans << '\n';
}

