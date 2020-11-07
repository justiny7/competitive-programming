//USACO Silver February 2020 Problem 3
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
//Yes worked first try
ifstream fin("clocktree.in");
ofstream fout("clocktree.out");

const int mxN=2501;
int n, c[mxN], clocks[mxN], ans;
vector<int> adj[mxN];
bool vis[mxN];

void resclocks() {
    for (int i=1; i<=n; ++i)
        clocks[i]=c[i];
}

void dfs(int v, int par=-1) {
    //cout << v << " " << par << " ";
    if (par>0) {
        clocks[v]++;
        if (clocks[v]>12)
            clocks[v]-=12;
    }
    //cout << clocks[v] << '\n';
    vis[v]=1;
    for (int u : adj[v])
        if (!vis[u])
            dfs(u, v);
    if (par>0) {
        clocks[par]+=13-clocks[v];
        if (clocks[par]>12)
            clocks[par]-=12;
        //cout << clocks[par] << '\n';
    }
}

bool works (int x) {
    resclocks();
    fill(vis+1, vis+n+1, 0);
    dfs(x);
    return (clocks[x]==12 || clocks[x]==1);
}

int main(void) {
    fin >> n;
    for (int i=1; i<=n; ++i)
        fin >> c[i];
    for (int i=1; i<n; ++i) {
        int a, b;
        fin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=1; i<=n; ++i)
        if (works(i))
            ans++;
    fout << ans << '\n';
}
