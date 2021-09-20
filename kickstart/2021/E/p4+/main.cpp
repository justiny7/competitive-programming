#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using ll = long long;

void solve() {
    ll n;
    cin >> n;

    cout << setprecision(6) << fixed;

    if (n <= 1e6) {
        ld ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += ld(1) / i;
        cout << ans << '\n';
    } else {
        cout << log(n) + 0.5772156649  << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

