//Yay worked first try
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1, mxL=20;
int n, t=1, q, in[mxN], out[mxN], a[mxN], bit[mxN<<1], dp[mxN][mxL], dep[mxN];
vector<int> adj[mxN];

void upd(int i, int x) {
    for (; i<mxN<<1; i+=i&-i)
        bit[i]^=x;
}
int query(int i) {
    int ans=0;
    for (; i; i-=i&-i)
        ans^=bit[i];
    return ans;
}
void dfs(int v=1, int p=0, int d=0) {
    in[v]=t++, dp[v][0]=p, dep[v]=d;
    for (int i=1; i<mxL; ++i)
        dp[v][i]=dp[dp[v][i-1]][i-1];
    for (int u:adj[v])
        if (u^p)
            dfs(u, v, d+1);
    out[v]=t++;
}
int lca(int v, int u) {
    if (dep[v]<dep[u])
        swap(v, u);
    for (int i=mxL-1; ~i; --i)
        if (dep[v]-(1<<i)>=dep[u])
            v=dp[v][i];
    if (v==u)
        return v;
    for (int i=mxL-1; ~i; --i)
        if (dp[v][i]^dp[u][i])
            v=dp[v][i], u=dp[u][i];
    return dp[v][0];
}

int main() {
    ifstream cin("cowland.in");
    ofstream cout("cowland.out");
    cin >> n >> q;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<n; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    dfs();
    for (int i=1; i<=n; ++i) {
        upd(in[i], a[i]);
        upd(out[i], a[i]);
    }
    while (q--) {
        int k, x, y;
        cin >> k >> x >> y;
        if (k==1) {
            upd(in[x], y^a[x]);
            upd(out[x], y^a[x]);
            a[x]=y;
        }
        else
            cout << (query(in[x])^query(in[y])^a[lca(x, y)]) << '\n';
    }
}

