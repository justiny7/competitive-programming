#include <bits/stdc++.h>
using namespace std;

const int N = 20;
int n, ans, dp[1 << N], pref[N], mn[N];
map<int, int> cnt[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        int &cur = pref[i];
        for (int j = 0; j < s.size(); ++j) {
            (s[j] == '(') ? ++cur : --cur;

            if (cur <= mn[i]) {
                mn[i] = cur;
                ++cnt[i][cur];
                // cout << "> " << i << " " << j << " " << cur << '\n';
            }
        }

        // cout << "! " << mn[i] << '\n';
    }

    memset(dp, 0xc0, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < (1 << n); ++i) {
        int here = 0;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                here += pref[j];

        if (here < 0)
            continue;

        for (int j = 0; j < n; ++j) {
            if (i & (1 << j))
                continue;

            int ni = i | (1 << j);
            if (here == -mn[j]) {
                dp[ni] = max(dp[ni], dp[i] + cnt[j][mn[j]]);
                ans = max(ans, dp[ni]);
            } else if (here > -mn[j]) {
                dp[ni] = max(dp[ni], dp[i]);
            } else {
                ans = max(ans, dp[i] + cnt[j][-here]);
            }
        }
    }

    cout << ans << '\n';
}

