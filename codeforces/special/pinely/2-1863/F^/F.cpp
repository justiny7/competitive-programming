#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), pref(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i] = a[i] ^ (i ? pref[i - 1] : 0);
    }

    auto f = [&](int l, int r) {
        return pref[r] ^ (l ? pref[l - 1] : 0);
    };

    vector<vector<bool>> dp(n, vector<bool>(n));
    vector<ll> msb_l(n), msb_r(n);
    vector<bool> ok_l(n), ok_r(n);
    auto upd_range = [&](int l, int r) {
        ll xsum = f(l, r);
        if (xsum) {
            int msb = 63 - __builtin_clzll(xsum);
            msb_l[l] |= (1LL << msb);
            msb_r[r] |= (1LL << msb);
        } else {
            ok_l[l] = ok_r[r] = 1;
        }

        dp[l][r] = 1;
    };

    upd_range(0, n - 1);
    for (int len = n - 1; len > 0; len--) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;

            ll here = f(l, r);
            if (ok_l[l] || ok_r[r] || (here & msb_l[l]) || (here & msb_r[r]))
                upd_range(l, r);
        }
    }

    for (int i = 0; i < n; i++)
        cout << dp[i][i];
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

