#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    ll res = 0, cur = 0;
    for (int i = 0; i <= n; ++i) {
        ll here = cur;
        
        ll d = 1;
        for (int j = i; j < n; ++j) {
            d *= 2;
            here += a[j] / d;

            if (d > 1e9)
                break;
        }

        res = max(res, here);

        if (i < n)
            cur += a[i] - k;
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


