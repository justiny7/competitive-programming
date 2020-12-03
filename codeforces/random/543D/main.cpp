#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
const ll M=1e9+7;
int n;
ll c[mxN], ans[mxN], where[mxN], par[mxN];
vector<int> adj[mxN];
vector<ll> pref[mxN], suff[mxN];

void dfs(int v=1, int p=0) {
    c[v]=1;
    for (int u:adj[v]) {
        dfs(u, v);
        c[v]=(c[v]*(c[u]+1))%M;
    }
}
void dfs2(int v=1, int p=0) {
    ans[v]=c[v];
    for (int u:adj[v]) {
        ll ou=c[u], ov=c[v];
        c[v]=(p?(c[p]+1)%M:1);
        if (where[u])
            c[v]=(c[v]*pref[v][where[u]-1])%M;
        if (where[u]<adj[v].size()-1)
            c[v]=(c[v]*suff[v][where[u]+1])%M;
        c[u]=(c[u]*(c[v]+1))%M;
        dfs2(u, v);
        c[v]=ov, c[u]=ou;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=2; i<=n; ++i) {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }
    dfs();
    for (int i=1; i<=n; ++i) {
        int sz=adj[i].size();
        pref[i].resize(sz);
        suff[i].resize(sz);
        for (int j=0; j<sz; ++j) {
            pref[i][j]=(j?pref[i][j-1]:1)*(c[adj[i][j]]+1)%M;
            suff[i][sz-j-1]=(j?suff[i][sz-j]:1)*(c[adj[i][sz-j-1]]+1)%M;
            where[adj[i][j]]=j;
        }
    }
    dfs2();
    for (int i=1; i<=n; ++i)
        cout << ans[i] << " \n"[i==n];
}

