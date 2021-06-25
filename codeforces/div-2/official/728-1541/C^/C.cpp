#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 69;
int n; ll a[N];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a, a + n);

    ll ans = a[n - 1], pref = 0;
    for (int i = 1; i < n; ++i) {
        pref += i * (a[i] - a[i - 1]);
        ans -= pref;
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--)
        solve();
}
