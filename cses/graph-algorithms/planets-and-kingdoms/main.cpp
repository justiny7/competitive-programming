#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=1e5+1;
int n, m, scc[mxN], cnt;
vector<int> adj[mxN], radj[mxN], ord;
bool vis[mxN];

void topo(int v) {
    vis[v]=1;
    for (int u:adj[v])
        if (!vis[u])
            topo(u);
    ord.pb(v);
}

void get_cmp(int v) {
    scc[v]=cnt;
    for (int u:radj[v])
        if (!scc[u])
            get_cmp(u);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        radj[b].pb(a);
    }
    for (int i=1; i<=n; ++i)
        if (!vis[i])
            topo(i);
    for (int i=n-1; i>=0; --i) {
        int v=ord[i];
        if (!scc[v])
            ++cnt, get_cmp(v);
    }
    cout << cnt << '\n';
    for (int i=1; i<=n; ++i) {
        if (i>1)
            cout << " ";
        cout << scc[i];
    }
    cout << '\n';
}
