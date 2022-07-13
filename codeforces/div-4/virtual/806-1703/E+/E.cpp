#include <bits/stdc++.h>
using namespace std;

array<int, 2> rot(array<int, 2> p, int n) {
    return {p[1], n - 1 - p[0]};
}

void solve() {
    int n;
    cin >> n;

    vector<vector<char>> g(n, vector<char>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];

    set<array<int, 2>> vis;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (vis.count({i, j}))
                continue;

            int o = 0, z = 0;

            int x = i, y = j;
            while (!vis.count({x, y})) {
                vis.insert({x, y});
                o += g[x][y] == '1';
                z += g[x][y] == '0';

                auto r = rot({x, y}, n);
                x = r[0], y = r[1];
            }

            res += min(o, z);
        }
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}


