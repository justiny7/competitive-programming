#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=3e5+1;
int n, m, c[mxN];
map<pii, int> mp;
vector<int> adj[mxN], ans;
bool vis[mxN];

void dfs(int v=1, int p=0) {
    vis[v]=1;
    for (int u:adj[v])
        if (!vis[u])
            dfs(u, v);
    if (c[v]&1) {
        ans.pb(mp[pii(v, p)]);
        c[p]^=1;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    {
        int cur=0, f=0;
        for (int i=1; i<=n; ++i) {
            cin >> c[i];
            if (~c[i])
                cur+=c[i];
            else
                f=1;
        }
        if (!f && (cur&1))
            return cout << "-1\n", 0;
        for (int i=1, p=0; i<=n; ++i)
            if (c[i]<0) {
                if (!p && (cur&1))
                    c[i]=p=1;
                else
                    c[i]=0;
            }
    }
    for (int i=1; i<=m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
        mp[pii(a, b)]=mp[pii(b, a)]=i;
    }
    dfs();
    cout << ans.size() << '\n';
    for (int i:ans)
        cout << i << '\n';
}

