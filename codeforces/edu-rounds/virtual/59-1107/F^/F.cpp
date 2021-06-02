#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//MCMF {{{
template<typename flow_t, typename cost_t> struct MCMF {
    const flow_t F_INF = numeric_limits<flow_t>::max();
    const cost_t C_INF = numeric_limits<cost_t>::max();

    struct Edge {
        int to, rev;
        flow_t flow, cap;
        cost_t cost;
    };

    int sz;
    vector<cost_t> p, dist;
    vector<pair<int, int>> prv;
    vector<vector<Edge>> adj;

    void init(int _sz) {
        sz = _sz;
        p.resize(sz), dist.resize(sz);
        prv.resize(sz), adj.resize(sz);
    }
    void add_edge(int u, int v, flow_t cap, cost_t cost) {
        adj[u].push_back({v, (int)adj[v].size(), 0, cap, cost});
        adj[v].push_back({u, (int)adj[u].size() - 1, 0, 0, -cost});
    }
    bool find_path(int src, int snk) {
        dist.assign(sz, C_INF);
        priority_queue<pair<cost_t, int>, vector<pair<cost_t, int>>, greater<>> pq;
        pq.emplace(dist[src] = 0, src);
        while (pq.size()) {
            auto [d, v] = pq.top(); pq.pop();
            if (dist[v] < d)
                continue;
            for (Edge &e : adj[v]) {
                if (e.flow < e.cap && dist[e.to] > d + e.cost + p[v] - p[e.to]) {
                    dist[e.to] = d + e.cost + p[v] - p[e.to], prv[e.to] = {v, e.rev};
                    pq.emplace(dist[e.to], e.to);
                }
            }
        }
        return (dist[snk] != C_INF);
    }
    pair<flow_t, cost_t> calc(int src, int snk) {
        for (int i = 0; i < sz; ++i)
            for (int v = 0; v < sz; ++v)
                for (Edge &e : adj[v])
                    if (e.cap)
                        p[e.to] = min(p[e.to], p[v] + e.cost);
        flow_t ret_flow = 0; cost_t ret_cost = 0;
        while (find_path(src, snk)) {
            for (int i = 0; i < sz; ++i)
                p[i] += dist[i];
            flow_t df = F_INF;
            for (int x = snk; x != src; x = prv[x].first) {
                Edge &e = adj[prv[x].first][adj[x][prv[x].second].rev];
                df = min(df, e.cap - e.flow);
            }
            ret_flow += df, ret_cost += (p[snk] - p[src]) * df;
            for (int x = snk; x != src; x = prv[x].first) {
                Edge &e = adj[x][prv[x].second];
                e.flow -= df, adj[prv[x].first][e.rev].flow += df;
            }
        }
        return {ret_flow, ret_cost};
    }
};
//}}}

int n, SRC, SNK;
MCMF<int, ll> g;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    g.init(n * 2 + 2);
    SNK = n * 2 + 1;
    for (int i = 1; i <= n; ++i) {
        ll a, b, k;
        cin >> a >> b >> k;
        g.add_edge(SRC, i, 1, 0);
        g.add_edge(i + n, SNK, 1, 0);
        for (ll p = 0; p < n; ++p)
            g.add_edge(i, p + n + 1, 1, -(max(a - min(p, k) * b, 0LL)));
    }
    cout << -g.calc(SRC, SNK).second << '\n';
}
