#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const int mxN=2e5+1;
ll n, k, child[mxN], depth[mxN], ans;
vector<int> adj[mxN];
bool vis[mxN];
multiset<ll, greater<ll>> tour;

void dfs(int i, int d=0) {
    vis[i]=1;
    child[i]=1;
    for (int u : adj[i])
        if (!vis[u]) {
            dfs(u, d+1);
            child[i]+=child[u];
        }
    tour.insert(child[i]-d-1);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1);
    int i=0;
    for (auto it=tour.begin(); i<n-k; ++i, ++it)
        ans+=*it;
    cout << ans << '\n';
}
