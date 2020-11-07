#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=1e5+1;
const ll MOD=1e9+7;
ll n, m, dist[mxN], cnt[mxN], cmin[mxN], cmax[mxN];
vector<pll> adj[mxN];
priority_queue<pll, vector<pll>, greater<pll>> pq;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    memset(dist, 0x3f, sizeof(dist));
    pq.push({0, 1});
    dist[1]=0, cnt[1]=1;
    while (!pq.empty()) {
        ll v=pq.top().se, d_v=pq.top().fi;
        pq.pop();
        if (dist[v]!=d_v)
            continue;
        for (auto& p:adj[v]) {
            ll u=p.fi, d=p.se;
            if (dist[v]+d<dist[u]) {
                dist[u]=dist[v]+d;
                cnt[u]=cnt[v];
                cmin[u]=cmin[v]+1;
                cmax[u]=cmax[v]+1;
                pq.push({dist[u], u});
            }
            else if (dist[v]+d==dist[u]) {
                cnt[u]=(cnt[u]+cnt[v])%MOD;
                cmin[u]=min(cmin[u], cmin[v]+1);
                cmax[u]=max(cmax[u], cmax[v]+1);
            }
        }
    }
    cout << dist[n] << " " << cnt[n] << " " << cmin[n] << " " << cmax[n] << '\n';
}
