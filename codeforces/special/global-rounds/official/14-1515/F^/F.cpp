#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5 + 69;
int n, m, par[N];
ll x, a[N];
set<pair<int, int>> adj[N];
set<int> cc[N];
priority_queue<array<ll, 3>> pq;

int find(int v) {
    return (v == par[v] ? v : par[v] = find(par[v]));
}
bool merge(int u, int v) {
    if ((u = find(u)) == (v = find(v)))
        return 0;
    if (cc[u].size() < cc[v].size())
        swap(u, v);
    for (int q : cc[v]) {
        cc[u].insert(q);
        while (1) {
            auto it = adj[u].lower_bound({q, 0});
            if (it->first == q)
                adj[u].erase(it);
            else
                break;
        }
    }
    cc[v].clear();
    for (auto q : adj[v])
        if (!cc[u].count(q.first))
            adj[u].insert(q);
    adj[v].clear();
    a[u] += a[v] - x, par[v] = u;
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> x;
    ll tot = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i], tot += a[i];
        pq.push({a[i], i, 1});
        par[i] = i;
        cc[i].insert(i);
    }
    if (tot < (ll)(n - 1) * x) {
        cout << "NO\n";
        return 0;
    }
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        adj[u].emplace(v, i);
        adj[v].emplace(u, i);
    }
    cout << "YES\n";
    while (pq.size()) {
        auto [d, v, sz] = pq.top(); pq.pop();
        if (cc[v].size() != sz || adj[v].empty())
            continue;
        /*
        cout << "EVERYTHING:\n";
        for (int i = 1; i <= n; ++i) {
            cout << "node " << i << " - " << find(i) << " " << a[find(i)] << '\n';
            for (auto [u, id] : adj[find(i)])
                cout << u << " " << id << '\n';
        }
        */
        auto [u, id] = *adj[v].begin();
        cout << id << '\n';
        //cout << "node " << v << " to be merged with " << u << '\n';
        merge(u, v);
        //assert(merge(u, v));
        v = find(v);
        pq.push({a[v], v, (ll)cc[v].size()});
        //cout << "pushing " << a[v] << " " << v << " " << cc[v].size() << '\n';
    }
}
