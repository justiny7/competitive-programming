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
        for (int i = 0; i < sz; ++i) cost[i] = {C_INF, 0};
        cost[src] = {0, F_INF};

        priority_queue<pair<cost_t, int>, vector<pair<cost_t, int>>, greater<>> pq;
        pq.emplace(0, src);
        while (pq.size()) {
            auto [d, v] = pq.top(); pq.pop();
            if (cost[v].first < d) continue;

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
            if (!find_path(src, snk)) return {tot_flow, tot_cost};
            backtrack(src, snk);
        }
    }
};
// }}}

const int N = 69;
int n, m, wins[N];
bool ans[N][N], done[N][N];
MCMF<int, int> g;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v, --u, --v;
        ans[u][v] = done[u][v] = done[v][u] = 1;
        ++wins[u];
    }

    int k = n * (n - 1) / 2, src = n + k, snk = n + k + 1;
    g.init(n + k + 2);

    for (int i = 0, ptr = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j, ++ptr) {
            if (done[i][j] || done[j][i])
                continue;

            g.add_edge(src, ptr, 1, 0);
            g.add_edge(ptr, i + k, 1, 0);
            g.add_edge(ptr, j + k, 1, 0);
        }

        for (int j = wins[i]; j < n; ++j)
            g.add_edge(i + k, snk, 1, j * 2 + 1);
    }

    g.calc(src, snk);

    for (int i = 0, ptr = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j, ++ptr) {
            if (done[i][j] || done[j][i])
                continue;

            for (auto e : g.adj[ptr]) {
                if (e.to == i + k && e.flow)
                    ans[i][j] = 1;
                else if (e.to == j + k && e.flow)
                    ans[j][i] = 1;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << ans[i][j];
        cout << '\n';
    }
}

