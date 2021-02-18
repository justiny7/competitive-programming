#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pl=pair<ll, ll>;
using ar3=array<ll, 3>;

const int mxN=1e5+1, mxW=51;
int n, m;
ll dist[mxN], from[mxN][mxW]; //from[i][j] = min cost getting to node i from an edge of weight j
vector<pl> adj[mxN];
priority_queue<ar3, vector<ar3>, greater<ar3>> pq;

int main() {
    memset(from, 0x3f, sizeof(from));
    memset(dist, 0x3f, sizeof(dist));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--) {
        ll a, b, x;
        cin >> a >> b >> x;
        adj[a].emplace_back(b, x);
        adj[b].emplace_back(a, x);
    }
    dist[1]=0;
    pq.push({0, 1, -1});
    while (pq.size()) {
        ar3 here=pq.top(); pq.pop();
        ll d=here[0], v=here[1], w=here[2];
        if (~w) {
            if (from[v][w]^d)
                continue;
            for (pl p:adj[v]) {
                ll u=p.first, nw=p.second, nd=from[v][w]+(w+nw)*(w+nw);
                if (dist[u]>nd) {
                    dist[u]=nd;
                    pq.push({nd, u, -1});
                }
            }
        }
        else {
            if (dist[v]^d)
                continue;
            for (pl p:adj[v]) {
                ll u=p.first, nw=p.second;
                if (from[u][nw]>d) {
                    from[u][nw]=d;
                    pq.push({d, u, nw});
                }
            }
        }
    }
    for (int i=1; i<=n; ++i)
        cout << (dist[i]^0x3f3f3f3f3f3f3f3f?dist[i]:-1) << " \n"[i==n];
}

