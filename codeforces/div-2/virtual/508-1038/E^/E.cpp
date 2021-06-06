#include <bits/stdc++.h>
using namespace std;

const int N = 169, K = 5;
int n, ans, dp[N][N][K][K];

int main() {
    memset(dp, 0xc0, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int l, r, w;
        cin >> l >> w >> r;
        dp[i][i][l][r] = dp[i][i][r][l] = w;
    }

    for (int i = n - 1; i; --i) {
        for (int j = i + 1; j <= n; ++j) {
            for (int p = 1; p < K; ++p) {
                for (int q = 1; q < K; ++q) {
                    for (int k = i; k < j; ++k) {
                        dp[i][j][p][q] = max({dp[i][j][p][q], dp[i][k][p][q], dp[k + 1][j][p][q]});
                        for (int r = 1; r < K; ++r) {
                            dp[i][j][p][q] = max({dp[i][j][p][q], dp[i][k][p][r] + dp[k + 1][j][r][q], dp[i][k][q][r] + dp[k + 1][j][r][p]});
                        }
                    }
                }
            }
        }
    }

    for (int i = 1; i < K; ++i)
        for (int j = 1; j < K; ++j)
            ans = max(ans, dp[1][n][i][j]);

    cout << ans << '\n';
}
