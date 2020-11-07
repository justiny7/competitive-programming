#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=1e5+1;
int n, m, k, vis[mxN];
vector<pll> adj[mxN];
priority_queue<pll, vector<pll>, greater<pll>> pq;
multiset<ll> ans;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while (m--) {
        ll a, b, c;
        cin >> a >> b >> c;
        adj[a].pb({b, c});
    }
    pq.push({0, 1});
    while (!pq.empty()) {
        ll cost=pq.top().fi, v=pq.top().se;
        pq.pop();
        ++vis[v];
        if (v==n) {
            ans.insert(cost);
            if (ans.size()==k)
                break;
        }
        if (vis[v]<=k)
            for (auto& p:adj[v]) {
                ll u=p.fi, c=p.se;
                pq.push({cost+c, u});
            }
    }
    bool f=1;
    for (ll i:ans) {
        if (!f)
            cout << " ";
        cout << i;
        f=0;
    }
    cout << '\n';
}
