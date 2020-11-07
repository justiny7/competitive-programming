#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ifstream fin("cowroute.in");
ofstream fout("cowroute.out");

const int mxN=1001;
int a, b, n;
pll dist[mxN], adj[mxN][mxN];
bool vis[mxN];

int main(void) {
    memset(adj, 0x3f, sizeof(adj));
    memset(dist, 0x3f, sizeof(dist));
    for (int i=1; i<mxN; ++i)
        adj[i][i]={0, 0};
    fin >> a >> b >> n;
    for (int i=1; i<=n; ++i) {
        int c, k;
        fin >> c >> k;
        vector<int> v(k);
        for (int j=0; j<k; ++j) {
            fin >> v[j];
            for (int l=0; l<j; ++l)
                adj[v[l]][v[j]]=min(adj[v[l]][v[j]], {c, j-l});
        }
    }
    dist[a]={0, 0};
    for (int i=0; i<mxN; ++i) {
        int v=0;
        for (int j=1; j<mxN; ++j)
            if (!vis[j] && (!v || dist[j]<dist[v]))
                v=j;
        vis[v]=1;
        for (int u=1; u<mxN; ++u) {
            ll d=dist[v].fi, len=dist[v].se;
            d+=adj[v][u].fi, len+=adj[v][u].se;
            dist[u]=min(dist[u], {d, len});
        }
    }
    if (dist[b].se>mxN) {
        fout << "-1 -1\n";
        return 0;
    }
    fout << dist[b].fi << " " << dist[b].se << '\n';
}
