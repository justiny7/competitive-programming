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
// }}}

const int N = 569;
int n, m, root[2], a[N], need[2][N], sz[2][N], rep[2][N], amt[2][N];
vector<int> adj[2][N];
MCMF<int, int> g;

void finish() {
    cout << "-1\n";
    exit(0);
}

int dfs(int c, int v, int p = 0, int cur = -1) {
    if (~need[c][v])
        cur = v;
    rep[c][v] = cur;

    int sum = 0;
    for (int u : adj[c][v])
        if (u != p)
            sum += dfs(c, u, v, cur);

    if (~need[c][v]) {
        if (sum > need[c][v])
            finish();

        amt[c][v] = need[c][v] - sum;
        sum = need[c][v];
    }

    return sum;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> root[0] >> root[1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int c = 0; c < 2; ++c) {
        for (int i = 1, u, v; i < n; ++i) {
            cin >> u >> v;
            adj[c][u].push_back(v);
            adj[c][v].push_back(u);
        }
    }

    memset(need, -1, sizeof(need));
    for (int c = 0; c < 2; ++c) {
        int q; cin >> q;
        while (q--) {
            int v, x;
            cin >> v >> x;
            need[c][v] = x;
        }
    }

    for (int c = 0; c < 2; ++c)
        dfs(c, root[c]);

    g.init(N * 2);
    for (int i = 1; i <= n; ++i) {
        g.add_edge(0, i, amt[0][i], 0);
        g.add_edge(n + i, n * 2 + 1, amt[1][i], 0);
        g.add_edge(rep[0][i], n + rep[1][i], 1, -a[i]);
    }

    auto [flo, cst] = g.calc(0, n * 2 + 1);
    if (flo != need[0][root[0]] || flo != need[1][root[1]])
        finish();

    cout << -cst << '\n';
}
