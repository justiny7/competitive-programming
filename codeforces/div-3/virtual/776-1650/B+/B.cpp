#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll l, r, a;
    cin >> l >> r >> a;

    ll res = (r / a) + (r % a);

    ll q = (r / a) * a + a - 1;
    while (q > r)
        q -= a;

    if (q >= l)
        res = max(res, (q / a) + (q % a));

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

