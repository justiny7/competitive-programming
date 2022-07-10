#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    int m;
    cin >> m;

    vector<ll> b(m);
    for (ll &i : b)
        cin >> i;

    vector<ll> pref_a(n + 1), pref_b(m + 1);
    for (int i = 0; i < n; ++i)
        pref_a[i + 1] = pref_a[i] + a[i];
    for (int i = 0; i < m; ++i)
        pref_b[i + 1] = pref_b[i] + b[i];

    int k;
    cin >> k;

    vector<ll> mx_a(min(n, k) + 1), mx_b(min(m, k) + 1);
    for (int i = 0; i < mx_a.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            ll here = pref_a[j] + (pref_a[n] - pref_a[n - (i - j)]);
            mx_a[i] = max(mx_a[i], here);
        }

        // cout << i << " " << mx_a[i] << '\n';
    }
    for (int i = 0; i < mx_b.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            ll here = pref_b[j] + (pref_b[m] - pref_b[m - (i - j)]);
            mx_b[i] = max(mx_b[i], here);
        }

        // cout << i << " " << mx_b[i] << '\n';
    }

    ll res = 0;
    for (int i = 0; i <= k; ++i)
        if (i < mx_a.size() && k - i < mx_b.size())
            res = max(res, mx_a[i] + mx_b[k - i]);

    cout << res << '\n';
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

