#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=3e3+1;
int n, m;
ll dist[mxN];
vector<pair<ll, ll>> adj[mxN];
vector<int> radj[mxN];
bool vis[mxN], vis2[mxN];

void dfs(int v=1) {
    vis[v]=1;
    for (auto [u, d]:adj[v])
        if (!vis[u])
            dfs(u);
}
void dfs2(int v=n) {
    vis2[v]=1;
    for (int u:radj[v])
        if (!vis2[u])
            dfs2(u);
}

int main() {
    memset(dist, 0xc0, sizeof(dist));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b; ll c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b, c);
        radj[b].push_back(a);
    }
    dfs(); dfs2();
    dist[1]=0;
    for (int i=0; i<=n; ++i) {
        bool relaxed=0, reachable=0;
        for (int v=1; v<=n; ++v) {
            for (auto [u, d]:adj[v]) {
                if (dist[u]<dist[v]+d) {
                    dist[u]=dist[v]+d;
                    relaxed=1;
                    reachable|=(vis[u] && vis2[u]);
                }
            }
        }
        if (!relaxed)
            break;
        if (i==n && reachable) {
            cout << "-1\n";
            return 0;
        }
    }
    cout << dist[n] << '\n';
}

