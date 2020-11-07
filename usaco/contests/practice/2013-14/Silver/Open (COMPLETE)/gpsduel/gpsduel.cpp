#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

ifstream fin("gpsduel.in");
ofstream fout("gpsduel.out");

const int mxN=1e4+1;
int n, m, dist1[mxN], dist2[mxN];
vector<pii> adj1[mxN], adj2[mxN], adj3[mxN];

int dijkstra(vector<pii> adj[mxN], int dist[], int source, int sink) {
    bool vis[mxN];
    memset(vis, 0, sizeof(vis));
    fill(dist+1, dist+n+1, INT_MAX);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[source]=0;
    pq.push({0, source});
    while (!pq.empty()) {
        int t=pq.top().se;
        pq.pop();
        if (vis[t])
            continue;
        vis[t]=1;
        for (auto& p:adj[t]) {
            if (vis[p.fi])
                continue;
            int u=p.fi, d=p.se;
            if (dist[t]+d<dist[u]) {
                dist[u]=dist[t]+d;
                pq.push({dist[u], u});
            }
        }
    }
    return dist[sink];
}

int main(void) {
    fin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        adj1[b].pb({a, c});
        adj2[b].pb({a, d});
    }
    dijkstra(adj1, dist1, n, 1);
    dijkstra(adj2, dist2, n, 1);
    for (int i=1; i<=n; ++i)
        for (int j=0; j<adj1[i].size(); ++j) {
            int u=adj1[i][j].fi, d1=adj1[i][j].se, d2=adj2[i][j].se, c=2;
            if (dist1[u]-dist1[i]==d1)
                --c;
            if (dist2[u]-dist2[i]==d2)
                --c;
            adj3[u].pb({i, c});
        }
    fout << dijkstra(adj3, dist1, 1, n) << '\n';
}
