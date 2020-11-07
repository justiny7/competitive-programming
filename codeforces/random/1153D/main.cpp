#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=3e5+1;
int n, ans[mxN], p[mxN], sz[mxN];
vector<int> adj[mxN];
bool m[mxN], leaf[mxN];

void prep(int v=1) {
    bool f=0;
    for (int u:adj[v])
        if (u^p[v])
            f=1, prep(u), sz[v]+=sz[u];
    if (!f)
        sz[v]=leaf[v]=1;
}

int dfs(int v=1) {
    if (leaf[v])
        return 1;
    int c=0;
    if (m[v]) {
        for (int u:adj[v]) {
            if (u==p[v])
                continue;
            int cur=dfs(u)-sz[u]+sz[v];
            c=max(c, cur);
        }
        return c;
    }
    for (int u:adj[v])
        if (u^p[v])
            c+=dfs(u);
    return (c-adj[v].size()+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> m[i];
    for (int i=2; i<=n; ++i) {
        cin >> p[i];
        adj[p[i]].pb(i);
    }
    prep();
    cout << dfs() << '\n';
}

