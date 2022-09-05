#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int Q = 1e9 + 69;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<vector<array<int, 2>>> cost(n), val(n);
    for (int i = 1; i <= m; ++i) {
        int e, t, p;
        cin >> e >> t >> p, --e;

        cost[e].push_back({t, i});
        val[e].push_back({p, i});
    }

    ll cur = 0;
    vector<int> res;
    for (int t = 0; t < n; ++t) {
        int sz = cost[t].size();
        vector<vector<array<int, 2>>> dp(sz + 1, vector<array<int, 2>>(101, {Q, Q}));

        // cout << "t: " << t << '\n';
        // cout << "sz: " << sz << '\n';
        // cout << "cur: " << cur << '\n';

        dp[0][0] = {0, 0};
        for (int i = 1; i <= sz; ++i) {
            for (int j = 0; j <= 100; ++j) {
                if (dp[i - 1][j][1] != Q)
                    dp[i][j] = min(dp[i][j], {dp[i - 1][j][0], j});

                int nval = min(100, j + val[t][i - 1][0]);
                int nc = dp[i - 1][j][0] + cost[t][i - 1][0];
                if (dp[i - 1][j][1] != Q && dp[i][nval][0] > nc)
                    dp[i][nval] = {nc, j};
            }
        }

        // cout << "tot cost: " << dp[sz][100][0] << '\n';
        // cout << "final step: " << dp[sz][100][1] << '\n';

        if (cur + dp[sz][100][0] > a[t]) {
            cout << "-1\n";
            return;
        }

        cur += dp[sz][100][0];

        int c = 100;
        for (int i = sz; i; --i) {
            // cout << "> " << i << " " << c << '\n';
            if (dp[i][c][1] != c)
                res.push_back(cost[t][i - 1][1]);

            c = dp[i][c][1];
        }

        assert(c == 0);
    }

    int sz = res.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; ++i)
        cout << res[i] << " \n"[i == sz - 1];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

