#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define BIG 1e18
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

ll n, m, dist[100001];
vector<pll> adj[100001];
bool vis[100001];
priority_queue<pll, vector<pll>, greater<pll>> pq;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    fill(dist+1, dist+n+1, BIG);
    dist[1]=0;
    pq.push({0, 1});
    while (!pq.empty()) {
        ll t=pq.top().se;
        pq.pop();
        if (vis[t])
            continue;
        vis[t]=1;
        for (int i=0; i<adj[t].size(); ++i) {
            if (vis[adj[t][i].fi])
                continue;
            ll u=adj[t][i].fi, d=adj[t][i].se;
            if (dist[t]+d<dist[u]) {
                dist[u]=dist[t]+d;
                pq.push({dist[u], u});
            }
        }
    }
    for (int i=1; i<=n; ++i) {
        if (i>1)
            cout << " ";
        cout << dist[i];
    }
    cout << '\n';
}
