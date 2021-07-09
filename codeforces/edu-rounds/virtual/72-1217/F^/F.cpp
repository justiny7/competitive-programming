#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69, RT = 1069;
int n, m;
array<int, 3> qu[N];
set<array<int, 2>> cur, all; // current edges used on this block, all cumulative edges so far
bool ans[N];

// DSU {{{
int par[N], sz[N];
stack<array<int, 2>> hist;

int find(int v, bool save = 1) {
    if (v == par[v])
        return v;
    return (save ? find(par[v], save) : par[v] = find(par[v], save));
}
bool merge(int u, int v, bool save = 1) {
    if ((u = find(u, save)) == (v = find(v, save)))
        return 0;

    if (sz[u] > sz[v])
        swap(u, v);

    par[u] = v, sz[v] += sz[u];
    if (save)
        hist.push({u, v});

    return 1;
}
void rollback() {
    auto [u, v] = hist.top(); hist.pop();
    sz[v] -= sz[u], par[u] = u;
}
// }}}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        auto &[t, u, v] = qu[i];
        cin >> t >> u >> v;
        if (u > v)
            swap(u, v);
    }

    for (int i = 0; i < m; ++i) {
        if (i % RT == 0) { // rebuild edges
            cur.clear();

            for (int j = 1; j <= n; ++j)
                par[j] = j, sz[j] = 1;

            set<array<int, 2>> pos;
            for (int j = i; j < min(i + RT, m); ++j) {
                auto [t, u, v] = qu[j];
                if (t & 1) {
                    pos.insert({u, v});
                    pos.insert({u % n + 1, v % n + 1});
                }
            }

            for (auto e : all) {
                if (pos.count(e))
                    cur.insert(e);
                else
                    merge(e[0], e[1], 0);
            }
        }

        auto [t, u, v] = qu[i];
        if (ans[i])
            u = u % n + 1, v = v % n + 1;
        if (u > v)
            swap(u, v);

        if (t & 1) {
            if (cur.count({u, v})) {
                all.erase({u, v});
                cur.erase({u, v});
            }
            else {
                all.insert({u, v});
                cur.insert({u, v});
            }

            ans[i + 1] = ans[i];
        }
        else {
            for (auto [eu, ev] : cur)
                merge(eu, ev);

            cout << (ans[i + 1] = (find(u) == find(v)));

            while (hist.size())
                rollback();
        }
    }

    cout << '\n';
}
