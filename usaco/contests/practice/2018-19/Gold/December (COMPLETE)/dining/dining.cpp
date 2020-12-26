#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

ifstream fin("dining.in");
ofstream fout("dining.out");

const int mxN=5e4+10, dummy=5e4+5;
int n, m, k;
vector<pll> adj[mxN];
ll dist[2][mxN], yum[mxN];
priority_queue<pll, vector<pll>, greater<pll>> pq;

void dijkstra(int i, int source) {
    memset(dist[i], 0x3f, sizeof(dist[i]));
    dist[i][source]=0;
    pq.push({0, source});
    while (!pq.empty()) {
        ll d_v=pq.top().fi, v=pq.top().se;
        pq.pop();
        if (dist[i][v]!=d_v)
            continue;
        for (auto& p:adj[v]) {
            ll d=p.se, u=p.fi;
            if (dist[i][v]+d<dist[i][u]) {
                dist[i][u]=dist[i][v]+d;
                pq.push({dist[i][u], u});
            }
        }
    }
}

int main() {
    fin >> n >> m >> k;
    while (m--) {
        int a, b, c;
        fin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    for (int i=0; i<k; ++i) {
        int a, b;
        fin >> a >> b;
        yum[a]=b;
    }
    dijkstra(0, n);
    for (int i=1; i<=n; ++i)
        if (yum[i])
            adj[dummy].pb({i, dist[0][i]-yum[i]});
    dijkstra(1, dummy);
    for (int i=1; i<n; ++i)
        fout << (dist[0][i]>=dist[1][i]) << '\n';
}

