#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=3e5+1;
int n, d[mxN], d_v=-1, mxv;
vector<int> adj[mxN];

void dfs(int v, int p=0, int dst=0) {
    if (dst>d_v)
        d_v=dst, mxv=v;
    d[v]=max(d[v], dst);
    for (int u:adj[v])
        if (u^p)
            dfs(u, v, dst+1);
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
    dfs(1), d_v=-1;
    dfs(mxv), d_v=-1;
    dfs(mxv);
    for (int i=1; i<=n; ++i)
        cout << d_v+(d[i]==d_v?1:0) << '\n';
}

