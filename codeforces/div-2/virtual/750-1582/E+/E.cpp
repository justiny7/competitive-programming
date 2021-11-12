#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e5 + 69, R = 450;
int n;
ll a[N], pref[N], dp[N][R];

void solve() {
    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    reverse(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + a[i];

    int r = ceil(sqrt(n * 2));
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= r; ++j)
            dp[i][j] = -1;

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1e18;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= r; ++j) {
            dp[i][j] = dp[i - 1][j];
            // cout << i << " " << j << " " << i - j << " " << dp[i - 1][j - 1] << '\n';
            if (i - j >= 0 && dp[i - j][j - 1] > pref[i] - pref[i - j])
                dp[i][j] = max(dp[i][j], pref[i] - pref[i - j]);
        }
    }

    for (int i = r; ~i; --i) {
        for (int j = 1; j <= n; ++j) {
            if (~dp[j][i]) {
                cout << i << '\n';
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

