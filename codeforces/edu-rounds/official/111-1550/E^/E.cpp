#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69, K = 17;
int n, k, dp[1 << K], consec[N][K], nxt[N][K];
string s;

bool ok(int x) {
    for (int i = n; ~i; --i) {
        for (int j = 0; j < k; ++j) {
            if (i == n)
                nxt[i][j] = -1;
            else
                nxt[i][j] = (consec[i][j] >= x ? i : nxt[i + 1][j]);
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < (1 << k); ++i) {
        if (dp[i] >= n)
            continue;

        for (int j = 0; j < k; ++j) {
            if (i & (1 << j))
                continue;

            int to = nxt[dp[i]][j];
            if (~to)
                dp[i | (1 << j)] = min(dp[i | (1 << j)], x + to);
        }
    }

    return dp[(1 << k) - 1] <= n;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k >> s;

    for (int i = n - 1; ~i; --i)
        for (int j = 0; j < k; ++j)
            if (s[i] == ('a' + j) || s[i] == '?')
                consec[i][j] = consec[i + 1][j] + 1;

    int lo = 0, hi = n;
    while (lo < hi) {
        int m = lo + hi + 1 >> 1;

        if (ok(m))
            lo = m;
        else
            hi = m - 1;
    }

    cout << lo << '\n';
}
