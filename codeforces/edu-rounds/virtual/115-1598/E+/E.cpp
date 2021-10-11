#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e3 + 69;
int n, m, q;
ll ans, dp[N][N][2];
bool state[N][N];

void pr() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cout << dp[i][j][0] << " " << dp[i][j][1] << "\t\n"[j == m];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> q;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j][0] = dp[i - 1][j][1] + 1;
            dp[i][j][1] = dp[i][j - 1][0] + 1;
            ans += dp[i][j][0] + dp[i][j][1] - 1;
        }
    }

    // pr();

    // cout << "! " << ans << '\n';

    while (q--) {
        int r, c;
        cin >> r >> c;

        state[r][c] ^= 1;
        for (int t = 0; t < 2; ++t) {
            bool f = t;
            for (int i = r, j = c; i <= n && j <= m; f ^= 1) {
                ans -= max(0LL, dp[i][j][0] + dp[i][j][1] - 1);
                if (state[i][j])
                    dp[i][j][0] = dp[i][j][1] = 0;
                else {
                    dp[i][j][0] = dp[i - 1][j][1] + 1;
                    dp[i][j][1] = dp[i][j - 1][0] + 1;
                    ans += dp[i][j][0] + dp[i][j][1] - 1;
                }

                // cout << "> " << i << " " << j << " " << state[i][j] << " " << ans << '\n';

                if (f)
                    ++i;
                else
                    ++j;
            }
        }

        // pr();
        
        cout << ans << '\n';
    }
}

