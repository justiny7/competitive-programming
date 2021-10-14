#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 41;
ll dp[N][N][N][N]; // dp[i][j][a][b] = path to having a mod A and b mod B using j A's out of the first i chars

ll binpow(ll b, ll e, ll MOD) {
    ll ret = 1;
    for (; e; (b *= b) %= MOD, e >>= 1)
        if (e & 1)
            (ret *= b) %= MOD;
    return ret;
}

void solve() {
    int n, A, B;
    cin >> n >> A >> B;

    string s;
    cin >> s;
    reverse(s.begin(), s.end());

    memset(dp, -1, sizeof(dp));
    dp[0][0][0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int a = 0; a < A; ++a) {
                for (int b = 0; b < B; ++b) {
                    if (dp[i][j][a][b] < 0)
                        continue;

                    int _a = (s[i] - '0') * binpow(10, j, A);
                    dp[i + 1][j + 1][(a + _a) % A][b] = dp[i][j][a][b] * 2;

                    int _b = (s[i] - '0') * binpow(10, i - j, B);
                    dp[i + 1][j][a][(b + _b) % B] = dp[i][j][a][b] * 2 + 1;
                }
            }
        }
    }

    int mn = INT_MAX;
    ll ans = -1;
    for (int j = 0; j <= n; ++j)
        if (~dp[n][j][0][0] && mn > abs(j * 2 - n))
            mn = abs(j * 2 - n), ans = j;

    if (ans <= 0 || ans == n) {
        cout << "-1\n";
        return;
    }

    // cout << mn << " " << ans << '\n';

    ans = dp[n][ans][0][0];
    for (int t = n; t--; ) {
        cout << ((ans & 1) ? 'B' : 'R');
        ans >>= 1;
    }
    
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

