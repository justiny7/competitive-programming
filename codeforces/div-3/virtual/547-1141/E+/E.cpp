#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    ll H;
    int n;
    cin >> H >> n;

    vector<ll> a(n), pref(n);
    for (ll &i : a)
        cin >> i;

    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        pref[i] = (cur += a[i]);
        if (H + cur <= 0) {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    if (cur >= 0) {
        cout << "-1\n";
        return 0;
    }

    ll tot = -pref[n - 1];
    ll ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        ll here = ((H + pref[i] + tot - 1) / tot) * n;
        ans = min(ans, here + i + 1);
    }

    cout << ans << '\n';
}

