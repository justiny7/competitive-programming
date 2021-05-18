#include <bits/stdc++.h>
using namespace std;

const int N = 88, M = 1e5 + 69;
int n, m, dp[M], l[N], r[N];
bool c[M];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x, s;
        cin >> x >> s;
        l[i] = max(0, x - s);
        r[i] = min(m, x + s);
        for (int j = l[i]; j <= r[i]; ++j)
            c[j] = 1;
    }
    for (int i = m; ~i; --i) {
        dp[i] = m - i;
        if (c[i] && c[i + 1])
            dp[i] = min(dp[i], dp[i + 1]);
        for (int j = 0; j < n; ++j) {
            if (l[j] > i) {
                int d = l[j] - i - 1;
                dp[i] = min(dp[i], dp[min(r[j] + d, m)] + d);
            }
        }
    }
    cout << dp[0] << '\n';
}
