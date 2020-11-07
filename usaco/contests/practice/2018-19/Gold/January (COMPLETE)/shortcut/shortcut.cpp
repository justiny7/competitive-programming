//YESS worked second try because overflow but I got the idea correct!!
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

ifstream fin("shortcut.in");
ofstream fout("shortcut.out");

const int mxN=1e4+1;
int n, m, t, c[mxN], dist[mxN], cnt[mxN];
long long ans;
vector<pii> adj[mxN];
vector<int> adj2[mxN];
priority_queue<pii, vector<pii>, greater<pii>> pq;
bool vis[mxN];

void dfs(int v=1) { //construct dijkstra tree
    vis[v]=1;
    int min_v=n;
    for (pii p:adj[v]) {
        int u=p.fi, d=p.se;
        if (dist[u]>dist[v] && !vis[u])
            dfs(u);
        else if (dist[u]+d==dist[v])
            min_v=min(min_v, u);
    }
    if (v^1)
        adj2[min_v].pb(v);
}

void dfs2(int v=1) {
    cnt[v]=c[v];
    for (int u:adj2[v]) {
        dfs2(u);
        cnt[v]+=cnt[u];
    }
}

int main() {
    fin >> n >> m >> t;
    for (int i=1; i<=n; ++i)
        fin >> c[i];
    for (int i=0; i<m; ++i) {
        int a, b, d;
        fin >> a >> b >> d;
        adj[a].pb({b, d});
        adj[b].pb({a, d});
    }
    memset(dist, 0x7f, sizeof(dist));
    dist[1]=0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int d_v=pq.top().fi, v=pq.top().se;
        pq.pop();
        if (d_v!=dist[v])
            continue;
        for (pii p:adj[v]) {
            int u=p.fi, d=p.se;
            if (dist[u]>dist[v]+d) {
                dist[u]=dist[v]+d;
                pq.push({dist[u], u});
            }
        }
    }
    dfs(); dfs2();
    for (int i=1; i<=n; ++i)
        ans=max(ans, 1LL*(dist[i]-t)*cnt[i]);
    fout << ans << '\n';
}

