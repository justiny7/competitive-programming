#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int mx = 0;
    vector<int> a(n);
    for (int &i : a)
        cin >> i, mx = max(mx, i);

    vector<int> dp(mx * 2 + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> ndp(mx * 2 + 1, 1e9);
        for (int j = 0; j <= mx * 2; ++j) {
            if (j + a[i] <= mx * 2)
                ndp[j + a[i]] = min(ndp[j + a[i]], max(dp[j] - a[i], 0));
            ndp[max(0, j - a[i])] = min(ndp[max(0, j - a[i])], dp[j] + a[i]);
        }

        swap(dp, ndp);
    }

    int ans = INT_MAX;
    for (int i = 0; i <= mx * 2; ++i)
        ans = min(ans, i + dp[i]);
    
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

