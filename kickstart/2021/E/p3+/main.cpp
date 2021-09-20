#include <bits/stdc++.h>
using namespace std;

const int N = 1069;
int n, m;
char g[N][N];
vector<vector<array<int, 2>>> hor, ver;

// DSU {{{
int par[N * N], sz[N * N];

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

int pack(array<int, 2> a) {
    return a[0] * m + a[1];
}

void solve() {
    cin >> n >> m;

    int orig = 0, fin = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            orig += (g[i][j] != '.' && g[i][j] != '#');
        }
    }
    
    for (int i = 0; i < n * m; ++i)
        par[i] = i, sz[i] = 1;

    hor.clear();
    ver.clear();

    for (int i = 0; i < n; ++i) {
        vector<array<int, 2>> cur;
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '#') {
                if (cur.size())
                    hor.push_back(cur);
                cur.clear();
            } else {
                cur.push_back({i, j});
            }
        }

        if (cur.size())
            hor.push_back(cur);
    }

    for (int i = 0; i < m; ++i) {
        vector<array<int, 2>> cur;
        for (int j = 0; j < n; ++j) {
            if (g[j][i] == '#') {
                if (cur.size())
                    ver.push_back(cur);
                cur.clear();
            } else {
                cur.push_back({j, i});
            }
        }

        if (cur.size())
            ver.push_back(cur);
    }
    
    for (auto &v : hor) {
        int sz = v.size();
        for (int i = 0; i < sz / 2; ++i)
            merge(pack(v[i]), pack(v[sz - i - 1]));
    }
    for (auto &v : ver) {
        int sz = v.size();
        for (int i = 0; i < sz / 2; ++i)
            merge(pack(v[i]), pack(v[sz - i - 1]));
    }

    map<int, char> id;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (g[i][j] != '.' && g[i][j] != '#')
                id[find(pack({i, j}))] = g[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (id.count(find(pack({i, j}))))
                g[i][j] = id[find(pack({i, j}))];
            fin += (g[i][j] != '#' && g[i][j] != '.');
        }
    }

    cout << fin - orig << '\n';
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << g[i][j];
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

