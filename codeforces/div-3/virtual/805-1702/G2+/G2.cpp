#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69, L = 18;
int n, q, t;
int tin[N], tout[N], dep[N], lift[N][L];
vector<int> adj[N];

void dfs(int v = 1, int p = 0, int d = 0) {
    tin[v] = t++;
    dep[v] = d;
    lift[v][0] = p;

    for (int i = 1; i < L; ++i)
        lift[v][i] = lift[lift[v][i - 1]][i - 1];

    for (int u : adj[v])
        if (u != p)
            dfs(u, v, d + 1);

    tout[v] = t++;
}

bool is_anc(int u, int v) {
    return (tin[v] <= tin[u] && tout[v] >= tout[u]);
}
int lca(int u, int v) {
    if (dep[u] > dep[v])
        swap(u, v);

    int dif = dep[v] - dep[u];
    for (int i = 0; i < L; ++i)
        if (dif & (1 << i))
            v = lift[v][i];

    if (u == v)
        return u;

    for (int i = L - 1; ~i; --i)
        if (lift[u][i] != lift[v][i])
            u = lift[u][i], v = lift[v][i];

    return lift[v][0];
}


int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    cin >> q;
    while (q--) {
        int k;
        cin >> k;

        vector<int> v(k);
        for (int &i : v)
            cin >> i;

        sort(v.begin(), v.end(), [&](int x, int y) {
            return dep[x] < dep[y];
        });

        int l = v[0];
        for (int i = 1; i < k; ++i)
            l = lca(l, v[i]);

        int a = l, b = l;
        bool f = 0;
        for (int i = 0; i < k; ++i) {
            int cur = v[i];

            if (is_anc(cur, l)) {
                if (is_anc(cur, a))
                    a = cur;
                else if (is_anc(cur, b))
                    b = cur;
                else {
                    f = 1;
                    break;
                }
            } else {
                f = 1;
                break;
            }

            // cout << "> " << i << " " << a << " " << b << " " << l << " " << lca(a, b) << '\n';
            if (lca(a, b) != l) {
                f = 1;
                break;
            }
        }

        cout << (f ? "NO" : "YES") << '\n';
    }

}


