#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=3e5+1;
const ll M=998244353;
int n, m, vis[mxN], c0, c1;
ll p[mxN];
vector<int> adj[mxN];

bool dfs(int v, int c=0) {
    vis[v]=c;
    c?++c1:++c0;
    for (int u:adj[v])
        if (vis[u]==c || (vis[u]<0 && !dfs(u, !c)))
            return 0;
    return 1;
}

void solve() {
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        adj[i].clear(), vis[i]=-1;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll ans=1;
    for (int i=1; i<=n; ++i) {
        if (~vis[i])
            continue;
        c0=c1=0;
        if (!dfs(i)) {
            cout << "0\n";
            return;
        }
        ans=(ans*(p[c1]+p[c0])%M)%M;
    }
    cout << ans << '\n';
}

int main() {
    p[0]=1;
    for (int i=1; i<mxN; ++i)
        p[i]=(2*p[i-1])%M;
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

