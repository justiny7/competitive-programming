#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    cin >> m;

    vector<int> b(m);
    for (int &i : b)
        cin >> i;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 1e9));
    for (int i = 0; i < m; ++i)
        dp[0][i] = 0;

    vector<int> pos[2501];
    for (int i = 0; i < m; ++i)
        pos[b[i]].push_back(i);

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            int need = a[i - 1];

            auto it = lower_bound(pos[need].begin(), pos[need].end(), j);
            if (it != pos[need].end())
                dp[i][*it] = min(dp[i][*it], dp[i - 1][j] + abs(*it - j));
            if (it != pos[need].begin()) {
                --it;
                dp[i][*it] = min(dp[i][*it], dp[i - 1][j] + abs(*it - j));
            }
        }
    }

    int res = INT_MAX;
    for (int i = 0; i < m; ++i)
        res = min(res, dp[n][i]);

    cout << res << '\n';
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

