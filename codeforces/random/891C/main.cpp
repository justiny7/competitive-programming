#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 69;

//DSU {{{
int sz[N], par[N];
stack<pair<int, int>> hist;

int find(int v) {
    return (v == par[v] ? v : find(par[v]));
}
bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
        return 0;

    if (sz[u] > sz[v])
        swap(u, v);
    par[u] = v, sz[v] += sz[u];
    hist.emplace(u, v);
    return 1;
}
void roll_back() {
    auto [u, v] = hist.top(); hist.pop();
    par[u] = u, sz[v] -= sz[u];
}
//}}}

int n, m, q, u[N], v[N], w[N];
vector<int> edges[N];
map<int, vector<int>> qu[N];
vector<array<int, 3>> events;
bool ans[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i] >> w[i];
        edges[w[i]].push_back(i);
    }

    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        int k; cin >> k;
        while (k--) {
            int x; cin >> x;
            qu[w[x]][i].push_back(x);
        }

        ans[i] = 1;
    }

    for (int i = 1; i <= n; ++i)
        par[i] = i, sz[i] = 1;

    for (int i = 1; i < N; ++i) {
        for (auto [k, vec] : qu[i]) {
            int c = 0;
            for (int j : vec) {
                int ret = merge(u[j], v[j]);
                ans[k] &= ret;
                c += ret;
            }

            while (c--)
                roll_back();
        }

        for (int j : edges[i])
            merge(u[j], v[j]);
    }

    for (int i = 0; i < q; ++i)
        cout << (ans[i] ? "YES" : "NO") << '\n';
}
