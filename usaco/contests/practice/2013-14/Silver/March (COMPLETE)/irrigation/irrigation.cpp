#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pii=pair<int, int>;

ifstream fin("irrigation.in");
ofstream fout("irrigation.out");

const int mxN=2e3+1;
vector<pii> adj[mxN];
pii pts[mxN];
int n, c, dist[mxN], ans;
bool vis[mxN], in[mxN];

int get_dist(pii a, pii b) {
    return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se);
}

int dfs(int v=0) {
    vis[v]=1;
    int cnt=1;
    for (pii u:adj[v])
        if (!vis[u.fi])
            cnt+=dfs(u.fi);
    return cnt;
}

int main(void) {
    fin >> n >> c;
    for (int i=0; i<n; ++i)
        fin >> pts[i].fi >> pts[i].se;
    for (int i=0; i<n; ++i)
        for (int j=i+1; j<n; ++j) {
            int d=get_dist(pts[i], pts[j]);
            if (d>=c) {
                adj[i].pb({j, d});
                adj[j].pb({i, d});
            }
        }
    if (dfs()<n) {
        fout << "-1\n";
        return 0;
    }
    memset(dist, 0x3f, sizeof(dist));
    dist[0]=0;
    for (int t=0; t<n; ++t) {
        int cmin=INT_MAX, v;
        for (int i=0; i<n; ++i)
            if (!in[i] && dist[i]<cmin)
                cmin=dist[i], v=i;
        ans+=dist[v], in[v]=1;
        for (pii u:adj[v])
            if (!in[u.fi] && u.se<dist[u.fi])
                dist[u.fi]=u.se;
    }
    fout << ans << '\n';
}


