#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
int n, k;
ll ans, sz[mxN];
vector<int> adj[mxN];
bool on[mxN];

void dfs(int v=1, int p=0) {
    for (int u:adj[v])
        if (u^p) {
            dfs(u, v);
            sz[v]+=sz[u];
        }
    ans+=min(sz[v], 2LL*k-sz[v]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1; i<=2*k; ++i) {
        int a; cin >> a;
        ++sz[a];
    }
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    cout << ans << '\n';
}

