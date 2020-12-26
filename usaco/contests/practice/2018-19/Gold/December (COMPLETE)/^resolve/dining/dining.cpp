//Yay worked first try
#include <bits/stdc++.h>
#define eb emplace_back
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;

const int mxN=5e4+1;
int n, m, k;
ll dist[mxN], dist2[mxN], bale[mxN];
vector<pll> adj[mxN];
priority_queue<pll, vector<pll>, greater<pll>> pq;

void dij(ll d[]) {
    while (pq.size()) {
        ll v, d_v;
        tie(d_v, v)=pq.top(); pq.pop();
        if (d[v]^d_v)
            continue;
        for (pll &u:adj[v]) {
            ll to=u.first, dst=d_v+u.second;
            if (dst<d[to])
                d[to]=dst, pq.emplace(dst, to);
        }
    }
}

int main() {
    memset(dist, 0x3f, sizeof(dist));
    memset(dist2, 0x3f, sizeof(dist2));
    ifstream cin("dining.in");
    ofstream cout("dining.out");
    cin >> n >> m >> k;
    while (m--) {
        int a, b; ll c;
        cin >> a >> b >> c;
        adj[a].eb(b, c);
        adj[b].eb(a, c);
    }
    while (k--) {
        int a; ll b;
        cin >> a >> b;
        bale[a]=max(bale[a], b);
    }
    pq.emplace(0, n);
    dist[n]=0;
    dij(dist);
    for (int i=1; i<=n; ++i)
        if (bale[i])
            pq.emplace(dist[i]-bale[i], i), dist2[i]=(dist[i]-bale[i]);
    dij(dist2);
    for (int i=1; i<n; ++i)
        cout << (dist[i]>=dist2[i]) << '\n';
}

