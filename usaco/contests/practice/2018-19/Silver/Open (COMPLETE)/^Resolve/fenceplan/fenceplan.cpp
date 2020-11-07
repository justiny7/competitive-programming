//Yay worked first try
#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
using pii=pair<int, int>;

const int mxN=1e5+1;
int n, m, l, r, b, u, ans=INT_MAX;
pii a[mxN];
vector<int> adj[mxN];
bool vis[mxN];

void dfs(int v) {
    vis[v]=1;
    l=min(l, a[v].x); r=max(r, a[v].x);
    b=min(b, a[v].y); u=max(u, a[v].y);
    for (int u:adj[v])
        if (!vis[u])
            dfs(u);
}

int main() {
    ifstream cin("fenceplan.in");
    ofstream cout("fenceplan.out");
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        cin >> a[i].x >> a[i].y;
    while (m--) {
        int a, b;
        cin >> a >>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for (int i=1; i<=n; ++i)
        if (!vis[i]) {
            l=INT_MAX, r=-1, b=INT_MAX, u=-1;
            dfs(i);
            ans=min(ans, 2*(u-b+r-l));
        }
    cout << ans << '\n';
}

