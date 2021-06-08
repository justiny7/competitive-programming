#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;

const int N = 1e5 + 69, L = 19;
int n, m, tt, sz[N], tin[N], tout[N], dep[N], lift[N][L];
array<int, 2> qv[N];
array<db, 4> qa[N];
vector<int> adj[N];
vector<array<int, 3>> qu[N];

//Segtree {{{
ll t[N * 4], lz[N * 4];

inline void push(int l, int r, int v) {
    if (l != r) {
        int m = l + r >> 1;
        t[v * 2] += lz[v] * (m - l + 1);
        t[v * 2 + 1] += lz[v] * (r - m);
        lz[v * 2] += lz[v];
        lz[v * 2 + 1] += lz[v];
    }
    lz[v] = 0;
}
void upd(int ql, int qr, ll x, int l = 0, int r = n - 1, int v = 1) {
    if (ql > r || qr < l)
        return;
    if (l >= ql && r <= qr) {
        t[v] += x * (r - l + 1);
        lz[v] += x;
        return;
    }
    push(l, r, v);
    int m = l + r >> 1;
    upd(ql, qr, x, l, m, v * 2);
    upd(ql, qr, x, m + 1, r, v * 2 + 1);
    t[v] = t[v * 2] + t[v * 2 + 1];
}
ll query(int ql, int qr, int l = 0, int r = n - 1, int v = 1) {
    if (ql > r || qr < l)
        return 0;
    if (l >= ql && r <= qr)
        return t[v];
    push(l, r, v);
    int m = l + r >> 1;
    return query(ql, qr, l, m, v * 2) + query(ql, qr, m + 1, r, v * 2 + 1);
}
//}}}

void dfs(int v = 1, int p = 0, int d = 1) {
    upd(tt, tt, d);
    dep[v] = d;
    tin[v] = tt++;
    sz[v] = 1;

    lift[v][0] = p;
    for (int i = 1; i < L; ++i)
        lift[v][i] = lift[lift[v][i - 1]][i - 1];

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
            sz[v] += sz[u];
        }
    }

    tout[v] = tt - 1;
}
bool is_anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
int jump(int v, int k) {
    for (int i = 0; i < L; ++i)
        if (k & (1 << i))
            v = lift[v][i];

    return v;
}
int lca(int u, int v) {
    if (dep[u] > dep[v])
        swap(u, v);

    v = jump(v, dep[v] - dep[u]);
    if (u == v)
        return u;

    for (int i = L - 1; ~i; --i)
        if (lift[u][i] != lift[v][i])
            u = lift[u][i], v = lift[v][i];

    return lift[u][0];
}
int dist(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
int get(int u, int v) { // second-to-last node on path from u --> v
    if (is_anc(v, u))
        return jump(u, abs(dep[v] - dep[u]) - 1);
    else
        return lift[v][0];
}
void dfs2(int v = 1, int p = 0) {
    for (auto [u, i, k] : qu[v]) {
        int q = get(u, v);
        db vsz = sz[v] - sz[q];
        db vsum = (is_anc(q, v) ? query(tin[v], tout[v]) : query(0, n - 1) - query(tin[q], tout[q]));
        qa[i][k * 2] = vsz, qa[i][k * 2 + 1] = vsum;
    }

    for (int u : adj[v]) {
        if (u == p)
            continue;

        upd(0, n - 1, 1);
        upd(tin[u], tout[u], -2);
        sz[v] -= sz[u];
        sz[u] += sz[v];

        dfs2(u, v);

        upd(tin[u], tout[u], 2);
        upd(0, n - 1, -1);
        sz[u] -= sz[v];
        sz[v] += sz[u];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        qv[i] = {u, v};
        qu[u].push_back({v, i, 0});
        qu[v].push_back({u, i, 1});
    }

    dfs(); dfs2();

    for (int i = 0; i < m; ++i) {
        // ans = (vsum * usz + usum * vsz + (nodes between u and v) * (usz * vsz)) / (usz * vsz)
        db ans = (qa[i][0] * qa[i][3] + qa[i][1] * qa[i][2] + (dist(qv[i][0], qv[i][1]) - 1) * (qa[i][0] * qa[i][2])) / (qa[i][0] * qa[i][2]);

        cout << setprecision(12) << fixed << ans << '\n';
    }
}
