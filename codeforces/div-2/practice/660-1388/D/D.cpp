#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=2e5+1;
int n, to[mxN];
ll ans, a[mxN];
vector<int> adj[mxN], roots, vans;

void dfs(int v) {
    for (int u:adj[v])
        dfs(u);
    if (a[v]>0) {
        ans+=a[v], vans.pb(v);
        if (~to[v])
            a[to[v]]+=a[v];
    }
}
void dfs2(int v) {
    if (a[v]<=0)
        ans+=a[v], vans.pb(v);
    for (int u:adj[v])
        dfs2(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    for (int i=1; i<=n; ++i) {
        cin >> to[i];
        if (~to[i])
            adj[to[i]].pb(i);
        else
            roots.pb(i);
    }
    for (int st:roots) {
        dfs(st); dfs2(st);
    }
    cout << ans << '\n';
    for (int i=0; i<n; ++i)
        cout << vans[i] << " \n"[i==n-1];
}

