#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, c[mxN], par[mxN], root;
vector<int> adj[mxN];
set<int> bad;

void dfs(int v=root) {
    int cnt=c[v];
    for (int u:adj[v])
        if (u^par[v]) {
            dfs(u);
            cnt+=c[u];
        }
    if (cnt==adj[v].size())
        bad.insert(v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i) {
        cin >> par[i] >> c[i];
        if (par[i]<0)
            ++par[i], root=i;
        adj[par[i]].pb(i);
        adj[i].pb(par[i]);
    }
    dfs();
    for (int i:bad)
        cout << i << " ";
    if (bad.empty())
        cout << -1;
    cout << '\n';
}

