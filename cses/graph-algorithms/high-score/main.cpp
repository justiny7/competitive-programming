#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=2510;
ll n, m, dist[mxN];
vector<pll> adj[mxN];
vector<ll> radj[mxN];
bool vis[mxN], vis2[mxN];

void dfs(int v=1) {
    vis[v]=1;
    for (pll u:adj[v])
        if (!vis[u.fi])
            dfs(u.fi);
}

void dfs2(int v=n) {
    vis2[v]=1;
    for (int u:radj[v])
        if (!vis2[u])
            dfs2(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(pll(b, c));
        radj[b].pb(a);
    }
    dfs(); dfs2();
    memset(dist, -0x7f, sizeof(dist));
    dist[1]=0;
    for (int i=0; i<=n; ++i) {
        bool has=0, reach=0;
        for (int v=1; v<=n; ++v)
            for (pll& p:adj[v])
                if (dist[v]+p.se>dist[p.fi])
                    reach|=(vis[p.fi] && vis2[p.fi]),
                    has=1, dist[p.fi]=dist[v]+p.se;
        if (!has)
            break;
        if (i==n && reach)
            return cout << "-1\n", 0;
    }
    cout << dist[n] << '\n';
}

