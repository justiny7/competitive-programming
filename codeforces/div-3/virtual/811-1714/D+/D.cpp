#include <bits/stdc++.h>
using namespace std;

void solve() {
    string t;
    int n;
    cin >> t >> n;

    map<string, int> s;
    for (int i = 1; i <= n; ++i) {
        string here;
        cin >> here;
        s[here] = i;
    }

    int sz = t.size();

    vector<array<int, 3>> dp(sz + 1, array<int, 3>{(int)1e9, (int)1e9, (int)1e9});
    dp[0] = {0, (int)1e9, (int)1e9};
    for (int i = 1; i <= sz; ++i) {
        for (int j = 0; j < i; ++j) {
            if (s.count(t.substr(j, i - j))) {
                array<int, 3> here = {dp[j][0] + 1, j, i};
                dp[i] = min(dp[i], here);
            }
        }

        for (int j = 0; j < i; ++j)
            dp[j] = min(dp[j], dp[i]);
    }

    if (dp[sz][0] == 1e9)
        cout << "-1\n";
    else {
        cout << dp[sz][0] << '\n';

        int ind = sz;
        while (ind > 0) {
            cout << s[t.substr(dp[ind][1], dp[ind][2] - dp[ind][1])] << " " << dp[ind][1] + 1 << '\n';
            ind = dp[ind][1];
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

