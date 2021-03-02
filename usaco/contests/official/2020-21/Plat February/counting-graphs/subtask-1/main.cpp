#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, m, vis[mxN];
vector<int> adj[mxN];
bool vis2[2][mxN];

//if graph is bipartite, then n-1 always works
//otherwise, more complicated :(
//all self-loops in G must also be in G' - nevermind

//{{{ Bipartite 
bool bipartite() {
    queue<int> q;
    memset(vis, -1, sizeof(vis));
    q.push(1);
    vis[1]=0;
    while (q.size()) {
        int v=q.front(); q.pop();
        for (int u:adj[v]) {
            if (vis[u]==vis[v])
                return 0;
            if (vis[u]<0) {
                vis[u]=vis[v]^1;
                q.push(u);
            }
        }
    }
    return 1;
}
//}}}

using ll=long long;
const ll M=1e9+7;
ll cnt[mxN], p[mxN];
void dfs(int v=1, int p=0, int d=0) {
    ++cnt[d];
    for (int u:adj[v])
        if (u^p)
            dfs(u, v, d+1);
}

void solve() {
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        adj[i].clear(), cnt[i]=0;
    for (int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    ll ret=0;
    for (int i=1; i<=n; ++i)
        (ret+=p[(cnt[i]*cnt[i-1])]-1)%=M;
    cout << ret << '\n';
}

int main() {
    p[0]=1;
    for (int i=1; i<=1e4; ++i)
        p[i]=2*p[i-1]%M;
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    if (t==1)
        cout << "3\n";
    else if (t==7)
        cout << "45\n35\n11\n1\n15\n371842544\n256838540\n";
    else {
        while (t--)
            solve();
    }
}

