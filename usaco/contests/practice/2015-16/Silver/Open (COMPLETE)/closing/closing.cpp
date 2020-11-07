//USACO Silver US Open 2016 Problem 3
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

ifstream fin("closing.in");
ofstream fout("closing.out");

int n, m, closing[3001], reached;
vector<int> adj[3001];
bool vis[3001], unreachable[3001];

void dfs(int u) {
    vis[u]=1;
    reached++;
    for (int i : adj[u])
        if (!vis[i] && !unreachable[i])
            dfs(i);
}

int main(void) {
    fin >> n >> m;
    for (int i=0; i<m; ++i) {
        int a, b;
        fin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=0; i<n; ++i)
        fin >> closing[i];
    for (int i=0; i<n; ++i) { //trying dfs after each removal before moving onto quicker methods
        reached=0;            //implemented adjlist and got it
        fill(vis+1, vis+1+n, 0);
        dfs(closing[n-1]);
        if (reached==n-i)
            fout << "YES\n";
        else
            fout << "NO\n";
        unreachable[closing[i]]=1;
    }
}
