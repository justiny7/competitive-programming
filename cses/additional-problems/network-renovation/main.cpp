#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n;
vector<int> adj[mxN], leaves;

void dfs(int v=1, int p=0) {
    for (int u:adj[v])
        if (u^p)
            dfs(u, v);
    if (adj[v].size()==1)
        leaves.pb(v);
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
    int sz=leaves.size(), ans=(sz+1)/2;
    cout << ans << '\n';
    for (int i=0; i<ans; ++i)
        cout << leaves[i] << " " << leaves[i+sz/2] << '\n';
}

