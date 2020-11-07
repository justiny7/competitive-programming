#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=1e5+1;
int n, m, in[mxN], vis[mxN];
pii a[mxN];
vector<int> adj[mxN], topo;
set<pii> edge;

bool dfs(int v) {
    vis[v]=1;
    for (int u:adj[v])
        if (vis[u]==1 || (!vis[u] && !dfs(u)))
            return 0;
    vis[v]=2;
    topo.pb(v);
    return 1;
}

bool works(int x) {
    topo.clear();
    edge.clear();
    for (int i=1; i<=n; ++i)
        adj[i].clear();
    memset(in, 0, sizeof(in));
    memset(vis, 0, sizeof(vis));
    for (int i=1; i<=x; ++i)
        adj[a[i].fi].pb(a[i].se), ++in[a[i].se], edge.insert(a[i]);
    int st=-1;
    for (int i=1; i<=n; ++i)
        if (!in[i]) {
            if (st<0)
                st=i;
            else
                return 0;
        }
    if (st<0 || !dfs(st) || topo.size()<n)
        return 0;
    for (int i=n-2; ~i; --i)
        if (!edge.count(pii(topo[i+1], topo[i])))
            return 0;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=m; ++i)
        cin >> a[i].fi >> a[i].se;
    int lo=1, hi=m, best=-1;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (works(mid))
            best=mid, hi=mid-1;
        else
            lo=mid+1;
    }
    cout << best << '\n';
}

