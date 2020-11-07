#include <bits/stdc++.h>
#define fi first
#define se second 
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

const ll BIG=1e18;
ll n, m, d[100001], d2[100001], ans=BIG;
vector<pll> adj[100001], radj[100001];
bool vis[100001];
priority_queue<pll, vector<pll>, greater<pll>> pq;

void dij(int st, vector<pll> vec[100001], ll dist[100001]) {
    fill(vis+1, vis+n+1, 0);
    fill(dist+1, dist+n+1, BIG);
    dist[st]=0;
    pq.push({0, st});
    while (!pq.empty()) {
        ll t=pq.top().se;
        pq.pop();
        if (vis[t])
            continue;
        vis[t]=1;
        for (auto& p : vec[t]) {
            if (vis[p.fi])
                continue;
            ll u=p.fi, dd=p.se;
            if (dist[u]>dist[t]+dd) {
                dist[u]=dist[t]+dd;
                pq.push({dist[u], u});
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        radj[b].push_back({a, c});
    }
    dij(1, adj, d);
    dij(n, radj, d2);
    for (int i=1; i<=n; ++i)
        for (auto& p : adj[i])
            ans=min(ans, d[i]+d2[p.fi]+p.se/2);
    cout << ans << '\n';
}
