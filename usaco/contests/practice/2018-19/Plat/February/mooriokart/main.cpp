#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1569, L = 13, M = 1e9 + 7, Y = 2569;
int n, m, cc, cmp[N], lift[N][L], dep[N];
ll x, y, d[N], dist[N][N];
vector<int> have[N];
vector<array<int, 2>> adj[N];
array<ll, 2> mp[Y], nxt[Y]; // mp[len of path] = {number of these paths, total length of these paths}

// Precomp {{{
void dfs(int v, int p = 0, int dd = 0) {
    cmp[v] = cc;
    dep[v] = dd;

    lift[v][0] = p;
    for (int i = 1; i < L; ++i)
        lift[v][i] = lift[lift[v][i - 1]][i - 1];

    for (auto [u, w] : adj[v]) {
        if (u == p)
            continue;

        d[u] = d[v] + w;
        dfs(u, v, dd + 1);
    }
}
int lca(int u, int v) {
    if (dep[u] < dep[v]) // u is deeper
        swap(u, v);

    int dif = dep[u] - dep[v];
    for (int i = 0; i < L; ++i)
        if (dif & (1 << i))
            u = lift[u][i];

    if (u == v)
        return u;

    for (int i = L - 1; ~i; --i)
        if (lift[u][i] != lift[v][i])
            u = lift[u][i], v = lift[v][i];

    return lift[u][0];
}
void prep_dist() {
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            if (cmp[i] == cmp[j])
                dist[i][j] = dist[j][i] = d[i] + d[j] - 2 * d[lca(i, j)];
}
// }}}

void add(array<ll, 2> &a, array<ll, 2> b) {
    (a[0] += b[0]) %= M;
    (a[1] += b[1]) %= M;
}
array<ll, 2> calc(array<ll, 2> pth1, array<ll, 2> pth2) {
    // num1 * num2 = # of new paths created
    // num1 * tot2 + num2 * tot1 = total length of new path created
    auto [num1, tot1] = pth1;
    auto [num2, tot2] = pth2;
    return {num1 * num2 % M, ((num1 * tot2 % M) + (num2 * tot1) % M) % M};
}

int main() {
    ifstream cin("mooriokart.in");
    ofstream cout("mooriokart.out");

    cin >> n >> m >> x >> y;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; ++i) {
        if (!cmp[i])
            ++cc, dfs(i);
        have[cmp[i]].push_back(i);
    }

    prep_dist();

    mp[min(y, cc * x)] = {1, cc * x};
    for (int i = 1; i <= cc; ++i) {
        map<int, array<ll, 2>> here;
        for (int v : have[i]) {
            for (int u : have[i]) {
                if (u > v) {
                    //cout << "> " << u << " " << v << " " << dist[u][v] << '\n';
                    add(here[min(y, dist[u][v])], {1, dist[u][v]});
                }
            }
        }

        for (int i = 0; i <= y; ++i)
            nxt[i] = {0, 0};

        for (auto [len, arr] : here) { // size of here bounded by sqrt(y)
            //cout << "! " << len << " " << arr[0] << " " << arr[1] << '\n';
            for (int j = 0; j <= y; ++j)
                add(nxt[min(y, (ll)j + len)], calc(mp[j], arr));
        }

        //for (int i = 0; i <= y; ++i)
        //cout << "? " << i << " " << nxt[i][0] << " " << nxt[i][1] << '\n';

        for (int j = 0; j <= y; ++j)
            mp[j] = nxt[j];
    }

    // cc! ways to order, 2^cc ways to choose direction of each path
    // but overcounts by 2 * cc because 2 directions * cc starting points
    ll ans = mp[y][1];
    for (int i = 1; i < cc; ++i)
        (ans *= (2 * i)) %= M;

    cout << ans << '\n';
}
