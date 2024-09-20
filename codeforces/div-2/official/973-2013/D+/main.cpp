#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &i : a) {
        cin >> i;
    }

    auto ok_max = [&](ll x) {
        ll s = 0;
        for (ll i : a) {
            if (i >= x) {
                s += i - x;
            } else {
                s -= min(s, x - i);
            }
        }

        return (s == 0);
    };

    ll lo = 1, hi = 1e12;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;

        if (ok_max(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    ll mx = lo;

    reverse(a.begin(), a.end());
    auto ok_min = [&](ll x) {
        ll s = 0;
        for (ll i : a) {
            if (i <= x) {
                s += x - i;
            } else {
                s -= min(s, i - x);
            }
        }

        return (s == 0);
    };

    lo = 1, hi = 1e12;
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;

        if (ok_min(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    cout << mx - lo << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
