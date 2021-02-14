#include <bits/stdc++.h>
using namespace std;

const int mxN=4e4+1;
int n, ans, mx, type[mxN], sz[mxN], closed[mxN], opened[mxN];
vector<int> adj[mxN];
bool vis[mxN];

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
void dfs_get(int v, int p, bool f, int unclosed, int dep, int cmax, int cmin) {
    dep+=(type[v]*(f?-1:1));
    cmax=max(cmax, dep);
    cmin=min(cmin, dep);
    if (~(type[v]*(f?-1:1)))
        ++unclosed;
    else
        unclosed=max(0, unclosed-1);
    if (!unclosed) {
        assert(dep<=0);
        if (f && closed[-dep]) //look for closing seq
            ans=max({ans, cmax-cmin, closed[-dep]});
        else if (!f && opened[-dep])
            ans=max({ans, cmax-cmin, opened[-dep]});
    }
    for (int u:adj[v])
        if (!vis[u] && u^p)
            dfs_get(u, v, f, unclosed, dep, cmax, cmin);
}
void dfs_upd(int v, int p, bool f, int unclosed=0, int dep=0, int cmax=0, int cmin=0) {
    dep+=(type[v]*(f?-1:1));
    mx=max(mx, -dep);
    cmax=max(cmax, dep);
    cmin=min(cmin, dep);
    if (~(type[v]*(f?-1:1)))
        ++unclosed;
    else
        unclosed=max(0, unclosed-1);
    if (!unclosed) {
        assert(dep<=0);
        if (f)
            opened[-dep]=max(opened[-dep], cmax-cmin);
        else
            closed[-dep]=max(closed[-dep], cmax-cmin);
    }
    for (int u:adj[v])
        if (!vis[u] && u^p)
            dfs_upd(u, v, f, unclosed, dep, cmax, cmin);
}
void decomp(int x=1) {
    int v=centroid(dfs(x), x);
    vis[v]=1, mx=0;
    for (int u:adj[v]) {
        if (!vis[u]) { //f is false -> closing sequence
            if (~type[v])
                ans=max(ans, closed[1]);
            else
                ans=max(ans, opened[1]);
            dfs_get(u, v, 0, (~type[v]?1:0), type[v], max(0, type[v]), min(0, type[v]));
            dfs_get(u, v, 1, (~type[v]?0:1), -type[v], max(0, -type[v]), min(0, -type[v]));
            dfs_upd(u, v, 0);
            dfs_upd(u, v, 1);
        }
    }
    fill(opened+1, opened+mx+1, 0);
    fill(closed+1, closed+mx+1, 0);
    for (int u:adj[v])
        if (!vis[u])
            decomp(u);
}

int main() {
    ifstream cin("btree.in");
    ofstream cout("btree.out");
    cin >> n;
    for (int i=2; i<=n; ++i) {
        int x; cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    for (int i=1; i<=n; ++i) {
        char c; cin >> c;
        type[i]=(c=='('?1:-1);
    }
    opened[0]=closed[0]=1;
    decomp();
    cout << ans << '\n';
}

