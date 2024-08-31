#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 5e5 + 5;
int n, q;

// Tree {{{
int dep[N], par[N], tin[N], tout[N];
ll a[N], sum[N];
vector<int> adj[N];

void dfs(int v = 1, int d = 0) {
    static int t = 1;

    tin[v] = t++, sum[v] = a[v], dep[v] = d;
    for (int u : adj[v]) {
        dfs(u, d + 1);
        sum[v] += max(sum[u], 0LL);
    }
    tout[v] = t - 1;
}
// }}}

// DSU {{{
int dsu[N];
int find(int v) {
    return (v == dsu[v] ? v : dsu[v] = find(dsu[v]));
}
bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) {
        return false;
    }
    if (dep[u] < dep[v]) { // highest depth is parent
        swap(u, v);
    }
    dsu[u] = v;
    return true;
}
// }}}

// BIT {{{
ll bit[N];

void upd(int i, ll x) {
    for (i++; i < N; i += i & -i) {
        bit[i] += x;
    }
}
ll query(int i) {
    ll res = 0;
    for (i++; i > 0; i -= i & -i) {
        res += bit[i];
    }
    return res;
}
ll query(int l, int r) {
    return query(r) - query(l - 1);
}

void upd_path(int u, int v, ll x) {
    if (dep[u] > dep[v]) {
        swap(u, v);
    }

    upd(tin[v], x);
    if (u != 1) {
        upd(tin[par[u]], -x);
    }
}
ll query_node(int v) {
    return query(tin[v], tout[v]);
}
// }}}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        dsu[i] = i;
    }

    for (int i = 2; i <= n; i++) {
        cin >> par[i];
        adj[par[i]].push_back(i);
    }

    dfs();
    
    for (int i = 2; i <= n; i++) {
        if (sum[i] >= 0) {
            merge(i, par[i]);
        }
    }

    auto get = [&](int v) {
        return sum[v] + query_node(v);
    };

    while (q--) {
        int x;
        ll c;
        cin >> x >> c;

        cout << get(x) + c << '\n';

        int v = x;
        while (true) {
            assert(v > 0);

            int p = find(v);
            upd_path(v, p, c);

            ll g = get(p);
            if (p == 1 || g < 0) {
                break;
            }
            if (g < c) {
                merge(p, par[p]);
                c = g;
            }

            v = par[p];
        }
    }
}
