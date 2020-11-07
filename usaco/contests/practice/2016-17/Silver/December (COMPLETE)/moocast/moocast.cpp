//USACO Silver December 2016 Problem 3
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using pii=pair<int, int>;
//Pretty easy problem except I got it on my second try cuz of a typo :c
//Also I misread the contraints so for the longest time I thought mxN=25,000 xd
ifstream fin("moocast.in");
ofstream fout("moocast.out");

bool can(pii a, pii b, int x) {
    return (a.fi-b.fi)*(a.fi-b.fi)+(a.se-b.se)*(a.se-b.se)<=x*x;
}

const int mxN=201;
int n, ans;
pair<pii, int> cows[mxN];
vector<int> adj[mxN];
bool vis[mxN];

int dfs(int u) {
    int tot=1;
    vis[u]=1;
    for (int v : adj[u])
        if (!vis[v])
            tot+=dfs(v);
    return tot;
}

int main(void) {
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> cows[i].fi.fi >> cows[i].fi.se >> cows[i].se;
    for (int i=0; i<n; ++i)
        for (int j=0; j<n; ++j)
            if (can(cows[i].fi, cows[j].fi, cows[i].se))
                adj[i].push_back(j);
    for (int i=0; i<n; ++i) {
        memset(vis, 0, sizeof(vis));
        ans=max(ans, dfs(i));
    }
    fout << ans << '\n';
}
