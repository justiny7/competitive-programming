#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define finish(x) return cout << x << '\n', 0
using namespace std;

const int mxN=2e5+1;
int n, m, d, o, grp[mxN], cnt;
vector<int> adj[mxN];
bool go[mxN], vis[mxN], seengrp[mxN];

void dfs(int v) {
    grp[v]=cnt;
    for (int u:adj[v])
        if (grp[u]<0)
            dfs(u);
}

void dfs2(int v) {
    vis[v]=1;
    for (int u:adj[v])
        if (!vis[u] && !go[u])
            cout << v << " " << u << '\n', dfs2(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> d;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        if (a==1 || b==1)
            ++o;
    }
    if (o<d)
        finish("NO");
    memset(grp, -1, sizeof(grp));
    grp[1]=0;
    for (int v:adj[1])
        if (grp[v]<0)
            ++cnt, dfs(v);
    if (cnt>d)
        finish("NO");
    cout << "YES\n";
    for (int i=0; i<adj[1].size(); ++i)
        if (!seengrp[grp[adj[1][i]]])
            go[adj[1][i]]=1, seengrp[grp[adj[1][i]]]=1, cout << "1 " << adj[1][i] << '\n';
    for (int i=0; cnt<d; ++i)
        if (!go[adj[1][i]])
            go[adj[1][i]]=1, ++cnt, cout << "1 " << adj[1][i] << '\n';
    vis[1]=1;
    for (int i=0; i<adj[1].size(); ++i)
        if (go[adj[1][i]])
            dfs2(adj[1][i]);
}

