#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> a(k);
    for (ll &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    int lo = 0, hi = k - 1;
    while (lo < hi) {
        int m = lo + hi >> 1;

        bool f = 1;
        ll cur = 0;
        for (int i = m; i < k; ++i) {
            if (cur >= a[i]) {
                f = 0;
                break;
            }

            cur += n - a[i];
        }

        if (f)
            hi = m;
        else
            lo = m + 1;
    }

    cout << k - lo << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

