#include <bits/stdc++.h>
using namespace std;

const int N = 69;
int n, dp[N][N][N][N];
char g[N][N];

void ckmin(int &a, int b) {
    a = min(a, b);
}

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> g[i][j];
    for (int xl = 1; xl <= n; ++xl) {
        for (int yl = 1; yl <= n; ++yl) {
            for (int i = 1; i + xl - 1 <= n; ++i) {
                for (int j = 1; j + yl - 1 <= n; ++j) {
                    if (xl == 1 && yl == 1) {
                        dp[i][j][1][1] = (g[i][j] == '#');
                        continue;
                    }
                    dp[i][j][xl][yl] = max(xl, yl);
                    for (int k = 1; k < xl; ++k)
                        ckmin(dp[i][j][xl][yl], dp[i][j][k][yl] + dp[i + k][j][xl - k][yl]);
                    for (int k = 1; k < yl; ++k)
                        ckmin(dp[i][j][xl][yl], dp[i][j][xl][k] + dp[i][j + k][xl][yl - k]);
                    //printf("%d %d %d %d %d\n", i, j, xl, yl, dp[i][j][xl][yl]);
                }
            }
        }
    }
    cout << dp[1][1][n][n] << '\n';
}
