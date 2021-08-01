#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 69, Q = 5e5 + 69, L = 20;
int n, q;
vector<array<int, 2>> adj[N];
array<int, 3> qu[Q];
bool ans[Q];

// DSU {{{
int par[N], sz[N];
int find(int v) {
    return (v == par[v] ? v : par[v] = find(par[v]));
}
bool merge(int u, int v) {
    if ((u = find(u)) == (v = find(v)))
        return 0;

    if (sz[u] > sz[v])
        swap(u, v);

    par[u] = v, sz[v] += sz[u];
    return 1;
}
// }}}

// Tree stuff {{{
int t, lift[N][L], xors[N], tin[N], tout[N];
void dfs(int v, int p, int cur = 0) {
    tin[v] = t++, xors[v] = cur;

    lift[v][0] = p;
    for (int i = 1; i < L; ++i)
        lift[v][i] = lift[lift[v][i - 1]][i - 1];

    for (auto [u, x] : adj[v])
        if (u != p)
            dfs(u, v, cur ^ x);

    tout[v] = t;
}
int is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
int lca(int u, int v) {
    if (is_anc(u, v))
        return u;
    if (is_anc(v, u))
        return v;

    for (int i = L - 1; ~i; --i)
        if (!is_anc(lift[v][i], u))
            v = lift[v][i];

    return lift[v][0];
}
// }}}

// BIT {{{
int bit[N];
void upd(int i, int x) {
    for (++i; i < N; i += i & -i)
        bit[i] += x;
}
int query(int i) {
    int ret = 0;
    for (++i; i; i -= i & -i)
        ret += bit[i];
    return ret;
}
void add_path(int st, int en) {
    while (st != en) {
        upd(tin[st], 1);
        upd(tout[st], -1);
        st = lift[st][0];
    }
}
// }}}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
        par[i] = i, sz[i] = 1;

    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < 3; ++j)
            cin >> qu[i][j];

        auto [u, v, x] = qu[i];
        if (merge(u, v)) {
            ans[i] = 1;
            adj[u].push_back({v, x});
            adj[v].push_back({u, x});
        }
    }

    memset(tin, -1, sizeof(tin));
    for (int i = 1; i <= n; ++i)
        if (tin[i] < 0)
            dfs(i, i);

    for (int i = 0; i < q; ++i) {
        if (ans[i])
            continue;

        auto [u, v, x] = qu[i];

        if ((xors[u] ^ xors[v] ^ x) == 0)
            continue;

        int l = lca(u, v);
        if (query(tin[u]) + query(tin[v]) - 2 * query(tin[l]))
            continue;

        ans[i] = 1;
        add_path(u, l);
        add_path(v, l);
    }

    for (int i = 0; i < q; ++i)
        cout << (ans[i] ? "YES" : "NO") << '\n';
}

