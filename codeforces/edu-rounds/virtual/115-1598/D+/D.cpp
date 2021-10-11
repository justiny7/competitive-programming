#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    vector<int> cnta(n + 1), cntb(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        ++cnta[a[i]], ++cntb[b[i]];
    }

    ll ans = 1LL * n * (n - 1) * (n - 2) / 6;
    for (int i = 0; i < n; ++i)
        ans -= 1LL * (cnta[a[i]] - 1) * (cntb[b[i]] - 1);

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

