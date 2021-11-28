#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 69;
int n, par[N], ans[N];
ll dp[N];
array<ll, 2> a[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 1; i <= n; ++i)
        cin >> a[i][0], a[i][1] = i;

    sort(a + 1, a + n + 1);

    memset(par, -1, sizeof(par));
    memset(dp, 0x3f, sizeof(dp));
    dp[1] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 2; j <= min(i + 4, n); ++j) {
            int here = a[j][0] - a[i][0];
            if (dp[j + 1] > dp[i] + here) {
                dp[j + 1] = dp[i] + here;
                par[j + 1] = i;
            }
        }
    }

    int cur = n + 1, cnt = 1;
    while (cur > 1) {
        for (int i = cur - 1; i >= par[cur]; --i)
            ans[a[i][1]] = cnt;
        cur = par[cur], ++cnt;
    }

    cout << dp[n + 1] << " " << cnt - 1 << '\n';
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " \n"[i == n];
}

