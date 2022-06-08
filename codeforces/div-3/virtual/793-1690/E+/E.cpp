#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        res += a[i] / k;
        a[i] %= k;
    }

    sort(a.begin(), a.end());

    int l = 0, r = n - 1;
    while (l < r) {
        if (a[l] + a[r] >= k) {
            ++res;
            --r;
        }
        ++l;
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

