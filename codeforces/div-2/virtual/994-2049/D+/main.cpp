#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<vector<ll>> g(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    // dp[i][j] = min cost to get to position (i, j)
    vector<ll> dp(m, 1e18);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<ll> ndp(m, 1e18), cur;

        for (int shift = 0; shift < m; shift++) {
            cur = vector<ll> (m, 1e18);

            for (int j = 0; j < m; j++) {
                cur[j] = min(cur[j], dp[j] + g[i][(j + shift) % m] + k * shift);
                if (j > 0) {
                    cur[j] = min(cur[j], cur[j - 1] + g[i][(j + shift) % m]);
                }

                ndp[j] = min(ndp[j], cur[j]);
            }
        }

        swap(dp, ndp);
    }

    cout << dp[m - 1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
