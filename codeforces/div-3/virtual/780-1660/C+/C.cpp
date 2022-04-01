#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> lst(26, -1), dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        int here = s[i - 1] - 'a';

        dp[i] = dp[i - 1] + 1;
        if (~lst[here])
            dp[i] = min(dp[lst[here] - 1] + (i - lst[here] - 1), dp[i - 1] + 1);

        lst[here] = i;
    }

    cout << dp[n] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

