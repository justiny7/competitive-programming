#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;
//Yay worked first try
ifstream fin("rblock.in");
ofstream fout("rblock.out");

const int mxN=251;
int n, m, ans, weight[mxN][mxN], par[mxN], dist[mxN];
vector<int> adj[mxN];

int dijkstra(bool p=0) {
    if (p)
        memset(par, -1, sizeof(par));
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 1});
    dist[1]=0;
    while (!pq.empty()) {
        int d_v=pq.top().fi, v=pq.top().se;
        pq.pop();
        if (d_v!=dist[v])
            continue;
        for (int u:adj[v]) {
            int d=weight[u][v];
            if (dist[v]+d<dist[u]) {
                dist[u]=dist[v]+d;
                if (p)
                    par[u]=v;
                pq.push({dist[u], u});
            }
        }
    }
    return dist[n];
}

int main(void) {
    fin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b, c;
        fin >> a >> b >> c;
        adj[a].pb(b);
        adj[b].pb(a);
        weight[a][b]=weight[b][a]=c;
    }
    int tot=dijkstra(1);
    for (int i=n; i!=1; i=par[i]) {
        weight[i][par[i]]*=2, weight[par[i]][i]*=2;
        ans=max(ans, dijkstra()-tot);
        weight[i][par[i]]/=2, weight[par[i]][i]/=2;
    }
    fout << ans << '\n';
}
