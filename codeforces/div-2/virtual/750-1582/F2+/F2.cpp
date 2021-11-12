#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 69, K = (1 << 13);
int n, dp[K], ndp[K];
vector<int> nxt[K], pos[K], res;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for (int t = 0; t < K; ++t) {
        for (int i = 0; i < K; ++i)
            ndp[i] = dp[i];
        for (int i = 0; i < K; ++i) {
            auto it = upper_bound(pos[t].begin(), pos[t].end(), dp[i]);
            if (it != pos[t].end())
                ndp[t ^ i] = min(ndp[t ^ i], *it);
        }

        for (int i = 0; i < K; ++i)
            dp[i] = ndp[i];
    }

    for (int i = 0; i < K; ++i)
        if (dp[i] != 0x3f3f3f3f)
            res.push_back(i);

    int sz = res.size();
    cout << sz << '\n';
    for (int i = 0; i < sz; ++i)
        cout << res[i] << " \n"[i == sz - 1];
}

