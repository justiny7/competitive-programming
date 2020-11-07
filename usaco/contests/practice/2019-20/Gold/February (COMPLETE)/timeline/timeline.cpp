//Yay got it first try
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using pii=pair<int, int>;;

const int mxN=1e5+1;
int n, m, c, s[mxN], ans[mxN];
vector<int> adj[mxN], topo;
vector<pii> radj[mxN];
bool vis[mxN];

void dfs(int v) {
    vis[v]=1;
    for (int u:adj[v])
        if (!vis[u])
            dfs(u);
    topo.pb(v);
}

int main() {
    ifstream cin("timeline.in");
    ofstream cout("timeline.out");
    cin >> n >> m >> c;
    for (int i=1; i<=n; ++i)
        cin >> s[i];
    for (int i=0; i<c; ++i) {
        int a, b, x;
        cin >> a >> b >> x;
        adj[a].pb(b);
        radj[b].pb(pii(a, x));
    }
    for (int i=1; i<=n; ++i)
        if (!vis[i])
            dfs(i);
    for (int i=n-1; ~i; --i) {
        int v=topo[i];
        ans[v]=s[v];
        for (pii j:radj[v])
            ans[v]=max(ans[v], ans[j.fi]+j.se);
    }
    for (int i=1; i<=n; ++i)
        cout << ans[i] << '\n';
}

