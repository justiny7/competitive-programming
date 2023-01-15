#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 1e3 + 69;

ll root(ll x) {
    ll lo = 0, hi = x;
    while (lo < hi) {
        ll m = lo + hi >> 1;

        if (m * m >= x)
            hi = m;
        else
            lo = m + 1;
    }

    return lo;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    ll u, MOD;
    cin >> t >> u;

    vector<ll> dp(N);
    if (u == 2) {
        cin >> MOD;

        dp[0] = 1;
        for (int t = 0; t < 4; ++t)
            for (int i = 1; i < N; ++i)
                for (int j = i; j < N; ++j)
                    dp[j] = (dp[j] + dp[j - i]) % MOD;
    }

    while (t--) {
        ll x;
        cin >> x;

        ll s1 = root(x),
           s2 = (s1 * (s1 - 1) >= x) ? s1 - 1 : s1;
        assert(s1 * s2 >= x);

        if (u & 1) {
            cout << s1 << " " << s2 << '\n';
            vector<vector<char>> res(s1, vector<char>(s2, '#'));

            int dif = s1 * s2 - x;
            assert(dif <= s1);
            for (int i = 0; i < dif; ++i)
                res[i][0] = '.';

            for (int i = 0; i < s1; ++i) {
                for (int j = 0; j < s2; ++j)
                    cout << res[i][j];
                cout << '\n';
            }
        } else {
            ll res = 0;

            while (s1 * s2 >= x) {
                (res += dp[s1 * s2 - x] * (s1 == s2 ? 1 : 2)) %= MOD;
                ++s1, --s2;
            }

            cout << (s1 + s2) * 2 << " " << res << '\n';
        }
    }
}

