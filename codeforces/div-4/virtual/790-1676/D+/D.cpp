#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];

    vector<vector<int>> rt = g, lf = g;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j > 0)
                rt[i][j] += rt[i - 1][j - 1];
            if (j < m - 1)
                lf[i][j] += lf[i - 1][j + 1];
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            if (j < m - 1)
                rt[i][j] = rt[i + 1][j + 1];
            if (j > 0)
                lf[i][j] = lf[i + 1][j - 1];
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            res = max(res, rt[i][j] + lf[i][j] - g[i][j]);

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}


