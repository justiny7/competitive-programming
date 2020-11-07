#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=3e5+1;
int n, q, d[mxN], lift[mxN][20];
vector<int> adj[mxN];

void dfs(int v=1, int p=1, int dep=0) {
    lift[v][0]=p, d[v]=dep;
    for (int i=1; i<20; ++i)
        lift[v][i]=lift[lift[v][i-1]][i-1];
    for (int u:adj[v])
        if (u^p)
            dfs(u, v, dep+1);
}

int lca(int a, int b) {
    if (d[a]<d[b])
        swap(a, b);
    for (int i=19; ~i; --i)
        if (d[a]>=d[b]+(1<<i))
            a=lift[a][i];
    if (a==b)
        return a;
    for (int i=19; ~i; --i)
        if (lift[a][i] && lift[a][i]^lift[b][i])
            a=lift[a][i], b=lift[b][i];
    return lift[a][0];
}

int jump(int v, int k) {
    int ans=v, c=k;
    for (int i=19; ~i; --i)
        if (c>=(1<<i))
            ans=lift[ans][i], c-=(1<<i);
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    cin >> q;
    while (q--) {
        int a, b, c, l;
        cin >> a >> b >> c, l=lca(a, b);
        if (d[a]+d[b]-2*d[l]<=c)
            cout << b << '\n';
        else if (d[a]-d[l]>=c)
            cout << jump(a, c) << '\n';
        else
            cout << jump(b, d[b]+d[a]-c-2*d[l]) << '\n';
    }
}

