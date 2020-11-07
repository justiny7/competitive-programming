#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=1e3+1;
ll n, m, k, d[mxN][mxN];
vector<pll> adj[mxN], edges, routes;

void dij(int src) {
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<bool> vis(n+1);
    pq.push(pll(0, src));
    while (pq.size()) {
        ll v, d_v;
        tie(d_v, v)=pq.top(); pq.pop();
        if (vis[v])
            continue;
        vis[v]=1, d[src][v]=d_v;
        for (pll u:adj[v])
            if (!vis[u.fi])
                pq.push(pll(d_v+u.se, u.fi));
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].pb(pll(b, c));
        adj[b].pb(pll(a, c));
        edges.pb(pll(a, b));
    }
    for (int i=1; i<=n; ++i)
        dij(i);
    while (k--) {
        int a, b;
        cin >> a >> b;
        routes.pb(pll(a, b));
    }
    ll ans=INT_MAX;
    for (pll e:edges) {
        ll cur=0;
        for (pll r:routes)
            if (r.fi^r.se)
                cur+=min({d[r.fi][r.se], d[r.fi][e.fi]+d[r.se][e.se], d[r.fi][e.se]+d[r.se][e.fi]});
        ans=min(ans, cur);
    }
    cout << ans << '\n';
}

