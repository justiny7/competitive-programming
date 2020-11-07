//Ayyy worked first try!!
//DFS+multisource BFS to find dists from each node to Bessie/farmers, then BFS from
//k to find all first nodes where farmers can reach it faster than Bessie
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ifstream fin("atlarge.in");
ofstream fout("atlarge.out");

const int mxN=1e5+1;
int n, k, c_dist[mxN], f_dist[mxN];
vector<int> adj[mxN], edges;
bool vis[mxN];

void dfs(int v=k, int p=-1, int d=0) {
    c_dist[v]=d;
    bool f=0;
    for (int u:adj[v])
        if (u!=p)
            f=1, dfs(u, v, d+1);
    if (!f)
        edges.pb(v);
}

int main() {
    fin >> n >> k;
    for (int i=1; i<n; ++i) {
        int a, b;
        fin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    queue<int> q;
    memset(f_dist, -1, sizeof(f_dist));
    for (int e:edges)
        q.push(e), f_dist[e]=0;
    while (!q.empty()) {
        int v=q.front(); q.pop();
        for (int u:adj[v])
            if (f_dist[u]<0) {
                f_dist[u]=f_dist[v]+1;
                q.push(u);
            }
    }
    int ans=0;
    q.push(k);
    vis[k]=1;
    while (!q.empty()) {
        int v=q.front(); q.pop();
        if (f_dist[v]<=c_dist[v]) {
            ++ans;
            continue;
        }
        for (int u:adj[v])
            if (!vis[u]) {
                vis[u]=1;
                q.push(u);
            }
    }
    fout << ans << '\n';
}
