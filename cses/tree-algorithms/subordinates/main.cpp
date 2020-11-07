#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e5+1;
int n, cnt[mxN];
vector<int> adj[mxN];
bool vis[mxN];

void dfs(int v=1) {
    vis[v]=1;
    for (int u:adj[v])
        if (!vis[u]) {
            dfs(u);
            cnt[v]+=1+cnt[u];
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=2; i<=n; ++i) {
        int a; cin >> a;
        adj[a].pb(i);
    }
    dfs();
    for (int i=1; i<=n; ++i) {
        if (i>1)
            cout << " ";
        cout << cnt[i];
    }
    cout << '\n';
}
