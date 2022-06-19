#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];

    if ((n + m - 1) & 1) {
        cout << "NO\n";
        return;
    }

    vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(m));
    dp[0][0] = {g[0][0], g[0][0]};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0 && j == 0)
                continue;

            int mx = INT_MIN, mn = INT_MAX;
            if (i > 0) {
                mn = min(mn, dp[i - 1][j][0]);
                mx = max(mx, dp[i - 1][j][1]);
            }
            if (j > 0) {
                mn = min(mn, dp[i][j - 1][0]);
                mx = max(mx, dp[i][j - 1][1]);
            }

            dp[i][j] = {mn + g[i][j], mx + g[i][j]};
        }
    }

    if (dp[n - 1][m - 1][0] <= 0 && dp[n - 1][m - 1][1] >= 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}

