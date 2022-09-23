#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

void solve() {
    string s, t;
    cin >> s >> t;

    int n = s.size(), m = t.size();

    set<int> occ;
    for (int i = 0; i + m <= n; ++i)
        if (s.substr(i, m) == t)
            occ.insert(i);

    vector<ll> dp(n + 1, INT_MAX), ways(n + 1);
    dp[n] = 0, ways[n] = 1;
    for (int i = n - 1; ~i; --i) {
        auto it = occ.lower_bound(i);
        if (it != occ.end()) {
            for (int j = *it; j + m <= n && j < *it + m; ++j)
                if (occ.count(j))
                    dp[i] = min(dp[i], dp[j + m] + 1);
            for (int j = *it; j + m <= n && j < *it + m; ++j)
                if (occ.count(j) && dp[i] == dp[j + m] + 1)
                    (ways[i] += ways[j + m]) %= MOD;
        }

        if (dp[i] == INT_MAX)
            dp[i] = 0, ways[i] = 1;
    }

    cout << dp[0] << " " << ways[0] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

