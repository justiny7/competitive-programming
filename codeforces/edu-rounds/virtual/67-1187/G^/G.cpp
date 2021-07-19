#include <bits/stdc++.h>
using namespace std;

// MCMF {{{
template<typename flow_t, typename cost_t> struct MCMF {
    const flow_t F_INF = numeric_limits<flow_t>::max();
    const cost_t C_INF = numeric_limits<cost_t>::max();

    struct Edge {
        int to, rev;
        flow_t flow, cap;
        cost_t cost;
    };

    int sz;
    cost_t tot_cost, cur_cost;
    flow_t tot_flow;
    vector<pair<int, int>> prv;
    vector<pair<cost_t, flow_t>> cost;
    vector<vector<Edge>> adj;

    void init(int _sz) {
        sz = _sz;
        cost.resize(sz);
        prv.resize(sz);
        adj.resize(sz);
    }
    void add_edge(int u, int v, flow_t cap, cost_t cost) {
        adj[u].push_back({v, (int)adj[v].size(), 0, cap, cost});
        adj[v].push_back({u, (int)adj[u].size() - 1, 0, 0, -cost});
    }
    void reweight() {
        for (int i = 0; i < sz; ++i)
            for (Edge &e : adj[i])
                e.cost += cost[i].first - cost[e.to].first;
    }
    bool find_path(int src, int snk) {
        for (int i = 0; i < sz; ++i)
            cost[i] = {C_INF, 0};
        cost[src] = {0, F_INF};

        priority_queue<pair<cost_t, int>, vector<pair<cost_t, int>>, greater<>> pq;
        pq.emplace(0, src);

        while (pq.size()) {
            auto [d, v] = pq.top(); pq.pop();
            if (cost[v].first < d)
                continue;

            for (Edge &e : adj[v]) {
                if (d + e.cost < cost[e.to].first && e.flow < e.cap) {
                    prv[e.to] = {v, e.rev};
                    cost[e.to] = {d + e.cost, min(e.cap - e.flow, cost[v].second)};
                    pq.emplace(cost[e.to].first, e.to);
                }
            }
        }

        cur_cost += cost[snk].first;
        return cost[snk].second;
    }
    void backtrack(int src, int snk) {
        flow_t f = cost[snk].second;
        tot_flow += f, tot_cost += cur_cost * f;

        for (int x = snk; x != src; x = prv[x].first) {
            adj[x][prv[x].second].flow -= f;
            adj[prv[x].first][adj[x][prv[x].second].rev].flow += f;
        }
    }
    pair<flow_t, cost_t> calc(int src, int snk) {
        tot_flow = tot_cost = cur_cost = 0;
        find_path(src, snk);
        while (1) {
            reweight();
            if (!find_path(src, snk))
                return {tot_flow, tot_cost};
            backtrack(src, snk);
        }
    }
};
// }}}

const int N = 5e3 + 69, T = 101;
int n, m, k, c, d;

int hsh(int v, int k) {
    return (v == 1) ? v : v + (n - 1) * k;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    MCMF<int, int> g;
    g.init(N);

    cin >> n >> m >> k >> c >> d;

    // from supersource (0) to each starting crossroad in time 0
    for (int i = 0; i < k; ++i) {
        int x; cin >> x;
        g.add_edge(0, hsh(x, 0), 1, 0);
    }

    while (m--) {
        int u, v;
        cin >> u >> v;

        // accounting for multiple people traveling along an edge
        // 1 + 3 + 5 + ... = x ^ 2
        for (int i = 0; i < T - 1; ++i) {
            for (int j = 0; j < k; ++j) {
                g.add_edge(hsh(u, i), hsh(v, i + 1), 1, c + d * (j * 2 + 1));
                g.add_edge(hsh(v, i), hsh(u, i + 1), 1, c + d * (j * 2 + 1));
            }
        }
    }

    // stay at a node from time j to time j + 1
    for (int i = 2; i <= n; ++i)
        for (int j = 0; j < T - 1; ++j)
            g.add_edge(hsh(i, j), hsh(i, j + 1), k, c);

    cout << g.calc(0, 1).second << '\n';
}
