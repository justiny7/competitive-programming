#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, c, d;
    cin >> n >> c >> d;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    // cout << "HI\n";

    sort(a.begin(), a.end(), greater<>());

    ll cur = 0;
    for (int i = 0; i < min(d, n); ++i)
        cur += a[i];

    if (cur >= c) {
        cout << "Infinity\n";
        return;
    }

    ll lo = 0, hi = d, best = -1;
    while (lo <= hi) {
        ll mid = lo + hi >> 1;

        cur = 0;
        for (int i = 0; i < d; ++i) {
            int ind = i % (mid + 1);
            if (ind < n)
                cur += a[ind];
        }

        if (cur >= c) {
            best = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    if (best < 0)
        cout << "Impossible\n";
    else
        cout << best << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

