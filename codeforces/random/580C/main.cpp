#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, m, ans;
vector<int> adj[mxN];
bool cat[mxN];

void dfs(int v=1, int p=0, int c=0) {
    if (c+cat[v]>m)
        return;
    bool f=0;
    for (int u:adj[v])
        if (u^p)
            f=1, dfs(u, v, cat[v]?c+1:0);
    if (!f)
        ++ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        cin >> cat[i];
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    cout << ans << '\n';
}


