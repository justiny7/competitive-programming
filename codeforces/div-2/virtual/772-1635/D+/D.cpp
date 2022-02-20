#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// either add 1 to bitwise representation or 2 0's
const int N = 2e5 + 69, MOD = 1e9 + 7;
ll dp[N]; // dp[i] = ways to fill up i spaces

int main() {
    cin.tie(0)->sync_with_stdio(0);

    dp[0] = 1;
    for (int i = 1; i < N; ++i) {
        dp[i] = dp[i - 1];
        if (i > 1)
            dp[i] += dp[i - 2];
        dp[i] %= MOD;
    }
    for (int i = 1; i < N; ++i)
        dp[i] = (dp[i] + dp[i - 1]) % MOD;

    int n, p;
    cin >> n >> p;

    set<int> all, pref;
    while (n--) {
        int x;
        cin >> x;
        all.insert(x);
    }

    for (int i : all) {
        int cur = i, here = i;
        while (cur > 0) {
            if (cur % 4 == 0)
                cur >>= 2;
            else if (cur & 1)
                cur >>= 1;
            else
                break;

            if (all.count(cur))
                here = cur;
        }

        pref.insert(here);
    }

    /*
    for (int i : pref)
        cout << i << " ";
    cout << '\n';
    */

    ll res = 0;
    for (int i : pref) {
        int len = 0;
        while ((1 << len) <= i)
            ++len;

        if (len <= p)
            res = (res + dp[p - len]) % MOD;
    }

    cout << res << '\n';
}

