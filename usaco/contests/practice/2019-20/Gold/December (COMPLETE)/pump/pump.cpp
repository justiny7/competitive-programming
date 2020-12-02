//Idea - maximizing flow/cost = minimizing cost/flow, so we can just run a pretty straightforward Dijkstra's
#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
using ll=long long;
using db=double;
using pll=pair<ll, ll>;

inline db get(ll c, ll f) {
    return db(db(db(c)/db(f))*db(1e6));
}

struct Edge {
    ll to, cost, flow;
};

struct node {
    ll x, cost, flow;
    bool operator<(const node& a) const {
        return get(cost, flow)>get(a.cost, a.flow);
    }
};

const int mxN=1e3+1;
int n, m;
pll dist[mxN];
vector<Edge> adj[mxN];
priority_queue<node> pq;

int main() {
    //ifstream cin("pump.in");
    //ofstream cout("pump.out");
    cin >> n >> m;
    while (m--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        adj[a].pb(Edge{b, c, d});
        adj[b].pb(Edge{a, c, d});
    }
    fill(dist+2, dist+n+1, pll(1e9, 1));
    dist[1]={0, 1e9};
    pq.push(node{1, 0, ll(1e9)});
    while (!pq.empty()) {
        ll c=pq.top().cost, f=pq.top().flow, v=pq.top().x;
        pq.pop();
        if (get(c, f)!=get(dist[v].fi, dist[v].se))
            continue;
        for (auto& p:adj[v]) {
            ll u=p.to, nc=(c+p.cost), nf=min(f, p.flow);
            if (get(nc, nf)<get(dist[u].fi, dist[u].se)) {
                dist[u]={nc, nf};
                pq.push(node{u, nc, nf});
            }
        }
    }
    //There's no way this is gonna work -_-
    //It worked :o
    cout << ll(get(dist[n].se, dist[n].fi)) << '\n';
}

