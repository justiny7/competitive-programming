#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5+1;
int n, sz[mxN], ans;
vector<int> adj[mxN];

void dfs(int v=1, int p=0) {
    sz[v]=1;
    bool f=1;
    for (int u:adj[v]) {
        if (u^p) {
            dfs(u, v);
            sz[v]+=sz[u];
            f&=(sz[u]*2<=n);
        }
    }
    f&=((n-sz[v])*2<=n);
    if (f)
        ans=v;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    cout << ans << '\n';
}

