#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 69, L = 21, M = 1e9 + 7;
int n, dp[N][L][2];

int p(int b, int e) {
    int ret = 1;
    while (e--)
        ret *= b;
    return ret;
}
int f(int x, int y) {
    return n / (p(2, x) * p(3, y));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    int mx = __lg(n);
    dp[1][mx][0] = 1;
    if (p(2, mx) / 2 * 3 <= n)
        dp[1][mx - 1][1] = 1;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < L; ++j) {
            for (int k = 0; k < 2; ++k) {
                (dp[i + 1][j][k] += (1LL * dp[i][j][k] * (f(j, k) - i)) % M) %= M;

                if (j > 0)
                    (dp[i + 1][j - 1][k] += (1LL * dp[i][j][k] * (f(j - 1, k) - f(j, k))) % M) %= M;
                if (k > 0)
                    (dp[i + 1][j][k - 1] += (1LL * dp[i][j][k] * (f(j, k - 1) - f(j, k))) % M) %= M;
            }
        }
    }

    cout << dp[n][0][0] << '\n';
}
