#include <bits/stdc++.h>
using namespace std;

const int N = 150069, V = 1e6 + 69;
int n, q, a[N];
set<int> adj[V];

int spf[V];
void sieve() {
    for (int i = 1; i < V; ++i)
        spf[i] = (i & 1) ? i : 2;

    for (long long i = 3; i < V; i += 2)
        if (spf[i] == i)
            for (long long j = i * i; j < V; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

int par[V], sz[V];
int find(int v) {
    return v == par[v] ? v : par[v] = find(par[v]);
}
bool merge(int u, int v) {
    if ((u = find(u)) == (v = find(v)))
        return 0;
    if (sz[u] > sz[v])
        swap(u, v);
    par[u] = v, sz[v] += sz[u];
    return 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    sieve();

    cin >> n >> q;

    for (int i = 0; i < V; ++i)
        par[i] = i, sz[i] = 1;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];

        int x = a[i];
        while (x > 1) {
            int d = spf[x];
            merge(d, spf[a[i]]);

            while (x % d == 0)
                x /= d;
        }
    }

    for (int i = 1; i <= n; ++i) {
        int x = a[i] + 1;

        vector<int> here = {find(spf[a[i]])};
        while (x > 1) {
            int d = spf[x];
            here.push_back(find(d));

            while (x % d == 0)
                x /= d;
        }

        for (int j : here)
            for (int k : here)
                if (j != k)
                    adj[j].insert(k);
    }

    while (q--) {
        int u, v;
        cin >> u >> v;

        u = find(spf[a[u]]), v = find(spf[a[v]]);

        if (u == v)
            cout << "0\n";
        else if (adj[u].count(v))
            cout << "1\n";
        else
            cout << "2\n";
    }
}
