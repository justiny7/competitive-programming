//Yay got it third try after some small bugs
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int mxN=5e4+1;
int n, m, vis[mxN], ans, cur, tot;
vector<int> adj[mxN];
bool f;

void dfs(int v) {
    cur+=vis[v], ++tot;
    for (int u:adj[v]) {
        if (f)
            return;
        if (~vis[u] && vis[u]==vis[v]) {
            f=1;
            break;
        }
        else if (vis[u]<0) {
            vis[u]=!vis[v];
            dfs(u);
        }
    }
}

int main() {
    memset(vis, -1, sizeof(vis));
    ifstream cin("decorate.in");
    ofstream cout("decorate.out");
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=1; i<=n; ++i)
        if (vis[i]<0) {
            tot=0, cur=0;
            vis[i]=0, dfs(i);
            ans+=max(cur, tot-cur);
        }
    cout << (f?-1:ans) << '\n';
}

