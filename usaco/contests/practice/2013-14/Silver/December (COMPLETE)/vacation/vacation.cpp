#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using pll=pair<ll, ll>;
//Yay worked first try
ifstream fin("vacation.in");
ofstream fout("vacation.out");

const int mxN=201;
int n, m, k, q, cnt;
ll to[mxN][mxN], from[mxN][mxN], ans;
vector<pll> adj[mxN], radj[mxN];

void dijkstra1(int source) {
    fill(to[source], to[source]+n+1, LLONG_MAX);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    to[source][source]=0;
    pq.push({0, source});
    while (!pq.empty()) {
        ll d_v=pq.top().fi, v=pq.top().se;
        pq.pop();
        if (d_v!=to[source][v])
            continue;
        for (auto& p:adj[v]) {
            ll u=p.fi, d=p.se;
            if (to[source][u]>to[source][v]+d) {
                to[source][u]=to[source][v]+d;
                pq.push({to[source][u], u});
            }
        }
    }
}

void dijkstra2(int source) {
    fill(from[source], from[source]+n+1, LLONG_MAX);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    from[source][source]=0;
    pq.push({0, source});
    while (!pq.empty()) {
        ll d_v=pq.top().fi, v=pq.top().se;
        pq.pop();
        if (d_v!=from[source][v])
            continue;
        for (auto& p:radj[v]) {
            ll u=p.fi, d=p.se;
            if (from[source][u]>from[source][v]+d) {
                from[source][u]=from[source][v]+d;
                pq.push({from[source][u], u});
            }
        }
    }
}

int main(void) {
    fin >> n >> m >> k >> q;
    while (m--) {
        ll a, b, c;
        fin >> a >> b >> c;
        adj[a].pb({b, c});
        radj[b].pb({a, c});
    }
    for (int i=1; i<=k; ++i) {
        dijkstra1(i);
        dijkstra2(i);
    }
    while (q--) {
        int a, b;
        fin >> a >> b;
        ll cur=LLONG_MAX;
        for (int i=1; i<=k; ++i)
            if (from[i][a]<LLONG_MAX && to[i][b]<LLONG_MAX)
                cur=min(cur, from[i][a]+to[i][b]);
        if (cur<LLONG_MAX)
            ans+=cur, ++cnt;
    }
    fout << cnt << '\n' << ans << '\n';
}
