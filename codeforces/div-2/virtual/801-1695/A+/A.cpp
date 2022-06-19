#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));
    int mx = INT_MIN;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            mx = max(mx, g[i][j]);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == mx) {
                int h = max(i + 1, n - i), w = max(j + 1, m - j);
                cout << h * w << '\n';
                return;
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

