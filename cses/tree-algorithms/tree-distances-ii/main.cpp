#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=2e5+1;
int n;
ll cnt[mxN], ans[mxN];
vector<int> adj[mxN];

void dfs(int v=1, int p=-1) {
    for (int u:adj[v])
        if (u!=p) {
            dfs(u, v);
            cnt[v]+=cnt[u], ans[v]+=ans[u]+cnt[u];
        }
}

void dfs2(int v=1, int p=-1) {
    for (int u:adj[v])
        if (u!=p) {
            ans[u]=ans[v]+n-2*cnt[u];
            dfs2(u, v);
        }
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
    fill(cnt+1, cnt+n+1, 1);
    dfs(); dfs2();
    for (int i=1; i<=n; ++i) {
        if (i>1)
            cout << " ";
        cout << ans[i];
    }
    cout << '\n';
}
