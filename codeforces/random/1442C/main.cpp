#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69, MD = 998244353, K = 21;
int n, m;
vector<int> adj[N][2];
bool vis[N][K];

struct dat {
    int v, k, dist;
    dat(int _v, int _k, int _dist) : v(_v), k(_k), dist(_dist) {}

    bool operator<(const dat &o) const {
        if (k == o.k)
            return dist > o.dist;
        if (k >= 20 || o.k >= 20)
            return k > o.k;
        return (1 << k) + dist > (1 << o.k) + o.dist;
    }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u][0].push_back(v);
        adj[v][1].push_back(u);
    }

    priority_queue<dat> pq;
    pq.emplace(1, 0, 0);
    while (pq.size()) {
        auto [v, k, dist] = pq.top(); pq.pop();

        int c = k & 1, nk = (k >= 20 ? (20 - c) : k);
        if (vis[v][nk])
            continue;

        vis[v][nk] = 1;

        if (v == n) {
            long long ans = 1;
            while (k--)
                (ans *= 2) %= MD;

            (ans += dist - 1 + MD) %= MD;
            cout << ans << '\n';

            return 0;
        }

        for (int u : adj[v][c])
            pq.emplace(u, k, dist + 1);
        pq.emplace(v, k + 1, dist);
    }

    assert(false);
}
