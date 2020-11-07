#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=1e5+1;
int n, m, cnt;
ll dist[mxN], ans;
vector<pll> adj[mxN];
priority_queue<pll, vector<pll>, greater<pll>> pq;
bool in[mxN];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
        adj[b].pb({a, c});
    }
    memset(dist, 0x7f, sizeof(dist));
    pq.push({0, 1});
    dist[1]=0;
    while (!pq.empty()) {
        int d=pq.top().fi, v=pq.top().se;
        pq.pop();
        if (in[v])
            continue;
        ans+=d, in[v]=1, ++cnt;
        for (auto& u:adj[v])
            if (!in[u.fi] && u.se<dist[u.fi]) {
                dist[u.fi]=u.se;
                pq.push({u.se, u.fi});
            }
    }
    if (cnt<n)
        cout << "IMPOSSIBLE\n";
    else
        cout << ans << '\n';
}
