#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n;
    cin >> n;

    ll lo = 1, hi = 2e9, res = 1e18;
    while (lo < hi) {
        ll m = lo + hi >> 1;

        ll here = m * (m - 1) / 2;
        if (here <= n) {
            res = min(res, m + n - here);
            lo = m + 1;
        } else {
            hi = m;
        }
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

