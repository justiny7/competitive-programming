//Yes worked first try! (w/ small hint from sol)
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=2e5+1;
int n, m, par[mxN], ans[mxN];
vector<int> adj[mxN], sz[mxN];
queue<int> q;

void merge(int a, int b) { //small-to-large merging w/ DSU
    a=par[a], b=par[b];
    if (a==b)
        return;
    if (sz[a].size()>sz[b].size())
        swap(a, b);
    for (int u:sz[a]) {
        par[u]=b;
        sz[b].pb(u);
    }
    for (int u:adj[a])
        adj[b].pb(u);
    adj[a].clear();
    if (adj[b].size()>1)
        q.push(b);
}

int main() {
    ifstream cin("fcolor.in");
    ofstream cout("fcolor.out");
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    for (int i=1; i<=n; ++i) {
        par[i]=i;
        sz[i].pb(i);
        if (adj[i].size()>1)
            q.push(i);
    }
    while (!q.empty()) {
        int v=q.front(); q.pop();
        while (adj[v].size()>1) {
            int u=adj[v].back(), t=adj[v][adj[v].size()-2];
            adj[v].pop_back();
            merge(u, t);
        }
    }
    int cur=1;
    for (int i=1; i<=n; ++i) {
        if (!ans[par[i]])
            ans[par[i]]=cur++;
        cout << ans[par[i]] << '\n';
    }
}

