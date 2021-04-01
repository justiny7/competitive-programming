#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1, L = 20;
int n, m, val[N], cmp[N];

//Tree stuff
int dep[N], lift[N][L];
vector<int> adj[N];

//PST stuff
const int SZ = 1e7 + 69;
int node = 1, rt[N], t[SZ], lc[SZ], rc[SZ];

//PST {{{
void dup(int &v) {
    ++node;
    lc[node] = lc[v];
    rc[node] = rc[v];
    t[node] = t[v];
    v = node;
}
void upd(int &v, int i, int l = 0, int r = n - 1) {
    dup(v);
    if (l == r) {
        ++t[v];
        return;
    }
    int m = l + r >> 1;
    if (i <= m)
        upd(lc[v], i, l, m);
    else
        upd(rc[v], i, m + 1, r);
    t[v] = t[lc[v]] + t[rc[v]];
}
int query(int va, int vb, int vl, int vp, int k, int l = 0, int r = n - 1) {
    if (l == r)
        return l;
    int m = l + r >> 1,
        cnt = t[lc[va]] + t[lc[vb]] - t[lc[vl]] - t[lc[vp]];
    if (cnt <= k)
        return query(rc[va], rc[vb], rc[vl], rc[vp], k - cnt, m + 1, r);
    else
        return query(lc[va], lc[vb], lc[vl], lc[vp], k, l, m);
}
//}}}

//Tree {{{
void dfs(int v = 1, int p = 0, int d = 0) {
    //Binary lifting stuff
    dep[v] = d;
    lift[v][0] = p;
    for (int i = 1; i < L; ++i)
        lift[v][i] = lift[lift[v][i - 1]][i - 1];

    //Update PST
    int pos = lower_bound(cmp, cmp + n, val[v]) - cmp;
    rt[v] = rt[p];
    upd(rt[v], pos);

    for (int u : adj[v])
        if (u != p)
            dfs(u, v, d + 1);
}
int lca(int a, int b) {
    if (dep[a] < dep[b])
        swap(a, b);
    for (int i = L - 1; ~i; --i)
        if (dep[a] - (1 << i) >= dep[b])
            a = lift[a][i];
    if (a == b)
        return a;
    for (int i = L - 1; ~i; --i)
        if (lift[a][i] != lift[b][i])
            a = lift[a][i], b = lift[b][i];
    return lift[a][0];
}
//}}}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> val[i], cmp[i - 1] = val[i];
    sort(cmp, cmp + n);
    for (int i = 1, a, b; i < n; ++i) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs();
    while (m--) {
        int u, v, k, l;
        cin >> u >> v >> k, l = lca(u, v);
        cout << cmp[query(rt[u], rt[v], rt[l], rt[lift[l][0]], k - 1)] << '\n';
    }
}
