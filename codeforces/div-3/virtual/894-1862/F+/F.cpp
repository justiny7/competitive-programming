#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int X = 1e6 + 69;

void solve() {
    ll w, f;
    cin >> w >> f;

    int n;
    cin >> n;

    ll tot = 0;
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i, tot += i;

    bitset<X> dp;
    dp[0] = 1;

    for (ll i : a)
        dp = dp | (dp << i);

    auto ok = [&](ll x) {
        ll cw = x * w, cf = x * f;

        for (int i = 1; i < X; ++i) {
            if (!dp[i])
                continue;

            ll left = tot - i;
            if (cw >= i && cf >= left || cw >= left && cf >= i)
                return 1;
        }

        return 0;
    };

    ll lo = 1, hi = 1e6;
    while (lo < hi) {
        ll m = lo + hi >> 1;

        if (ok(m))
            hi = m;
        else 
            lo = m + 1;
    }

    cout << lo << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

