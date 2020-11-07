//Had to look at solution T-T
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

ifstream fin("dirtraverse.in");
ofstream fout("dirtraverse.out");

const int mxN=1e5+1;
int n;
ll downcost[mxN], cost[mxN], anscost[mxN], files[mxN], ans=LLONG_MAX, fcnt;
vector<int> adj[mxN];
bool isleaf[mxN];

void dfs(int v=1, int p=-1) {
    for (int u:adj[v])
        if (u!=p) {
            dfs(u, v);
            downcost[v]+=(cost[u]+(!isleaf[u]))*files[u]+downcost[u];
            files[v]+=files[u];
        }
    if (isleaf[v])
        files[v]=1;
}

void dfs2(int v=1, int p=-1, ll parlen=0) {
    anscost[v]=parlen+downcost[v];
    if (!isleaf[v])
        ans=min(ans, anscost[v]);
    ll cur=0;
    for (int u:adj[v])
        if (u!=p)
            cur+=downcost[u]+files[u]*(cost[u]+(!isleaf[u]));
    for (int u:adj[v])
        if (u!=p)
            dfs2(u, v, parlen+cur-(downcost[u]+files[u]*(cost[u]+(!isleaf[u])))+3*(fcnt-files[u]));
}

int main() {
    fin >> n;
    for (int i=1; i<=n; ++i) {
        string s; fin >> s;
        cost[i]=s.size();
        int t; fin >> t;
        adj[i].resize(t);
        for (int j=0; j<t; ++j)
            fin >> adj[i][j];
        if (!t)
            isleaf[i]=1, ++fcnt;
    }
    dfs(); dfs2();
    fout << ans << '\n';
}

