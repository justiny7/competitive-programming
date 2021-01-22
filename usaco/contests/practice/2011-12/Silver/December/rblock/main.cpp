#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=101;
int n, m, par[mxN];
ll cur, mx, adj[mxN][mxN];
vector<int> sp;

ll dij(bool f=0) {
    ll dist[mxN];
    bool vis[mxN];
    memset(dist, 0x3f, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    dist[1]=0;
    while (1) {
        int v=-1;
        for (int i=1; i<=n; ++i)
            if (!vis[i] && (v<0 || dist[i]<dist[v]))
                v=i;
        if (v<0)
            break;
        vis[v]=1;
        for (int i=1; i<=n; ++i) {
            if (dist[v]+adj[v][i]<dist[i]) {
                dist[i]=dist[v]+adj[v][i];
                if (f)
                    par[i]=v;
            }
        }
    }
    return dist[n];
}

int main() {
    memset(adj, 0x3f, sizeof(adj));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b; ll c;
        cin >> a >> b >> c;
        adj[a][b]=adj[b][a]=c;
    }
    ll cur=dij(1);
    for (int v=n; par[v]; v=par[v])
        sp.push_back(v);
    for (int v:sp) {
        adj[v][par[v]]<<=1;
        adj[par[v]][v]<<=1;
        mx=max(mx, dij());
        adj[v][par[v]]>>=1;
        adj[par[v]][v]>>=1;
    }
    cout << mx-cur << '\n';
}

