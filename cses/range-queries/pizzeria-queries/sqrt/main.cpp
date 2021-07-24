#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69, R = 1e3 + 69;
int n, q, a[N], dp[N];
array<int, 3> qu[N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    for (int i = 0; i < q; ++i) {
        cin >> qu[i][0] >> qu[i][1];
        if (qu[i][0] & 1)
            cin >> qu[i][2];
    }

    dp[0] = dp[n + 1] = 2e9;

    vector<int> ch; // indices that change on this block
    for (int i = 0; i < q; ++i) {
        if (i % R == 0) {
            for (int i = 1; i <= n; ++i)
                dp[i] = a[i];

            ch.clear();
            for (int j = i; j < min(q, i + R); ++j) {
                if (qu[j][0] & 1) {
                    ch.push_back(qu[j][1]);
                    dp[qu[j][1]] = 2e9;
                }
            }

            // recalc dp
            for (int j = 1; j <= n; ++j)
                dp[j] = min(dp[j], dp[j - 1] + 1);
            for (int j = n; j; --j)
                dp[j] = min(dp[j], dp[j + 1] + 1);
        }

        if (qu[i][0] & 1)
            a[qu[i][1]] = qu[i][2];
        else {
            int ret = dp[qu[i][1]];
            for (int j : ch)
                ret = min(ret, a[j] + abs(j - qu[i][1]));

            cout << ret << '\n';
        }
    }
}
