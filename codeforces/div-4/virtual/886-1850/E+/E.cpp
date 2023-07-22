#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll c;
    cin >> n >> c;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    ll lo = 1, hi = 1e9;
    while (lo < hi) {
        ll m = lo + hi + 1 >> 1;

        ll here = 0;
        for (ll i : a)
            here = min((ll)(1e18), here + (i + 2 * m) * (i + 2 * m));

        if (here > c)
            hi = m - 1;
        else
            lo = m;
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

