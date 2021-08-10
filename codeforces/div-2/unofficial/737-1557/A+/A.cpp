#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    ll sum = 0;
    for (int i = 0; i < n - 1; ++i)
        sum += a[i];

    ld ans = (ld)sum / (ld)(n - 1);
    ans += a.back();

    cout << setprecision(10) << fixed << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

