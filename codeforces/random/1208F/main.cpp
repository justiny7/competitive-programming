#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 69, L = 21;
int n, a[N], dp[1 << L][2]; // dp[i] stores 2 rightmost positions of supermasks of i

int main() {
    cin.tie(0)->sync_with_stdio(0);

    memset(dp, -1, sizeof(dp));

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (~dp[a[i]][1])
            dp[a[i]][0] = dp[a[i]][1];
        dp[a[i]][1] = i;
    }

    for (int i = 0; i < L; ++i) {
        for (int j = 0; j < (1 << L); ++j) {
            if (j & (1 << i)) {
                int k = j ^ (1 << i);

                int srt[5] = {-1, dp[k][0], dp[k][1], dp[j][0], dp[j][1]};
                sort(srt, srt + 5);

                dp[k][1] = srt[4];
                
                int c = 4;
                while (c > 0 && srt[c] == srt[4])
                    --c;

                dp[k][0] = srt[c];
            }
        }
    }

    int ans = 0;
    for (int i = n - 3; ~i; --i) {
        // max pairwise & of elements a[i] | a[i + 1] ... a[i] | a[n]
        int here = 0;
        for (int j = L - 1; ~j; --j) {
            if (a[i] & (1 << j))
                continue;

            // count how many of a[i + 1] ... a[n] are supermasks of here | (1 << j)
            if (dp[here | (1 << j)][0] > i)
                here |= (1 << j);
        }

        ans = max(ans, a[i] | here);
    }

    cout << ans << '\n';
}

