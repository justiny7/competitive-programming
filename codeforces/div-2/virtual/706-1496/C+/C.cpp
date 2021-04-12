#include <bits/stdc++.h>
using namespace std;
using ld = long double;

void solve() {
    int n; cin >> n;
    vector<ld> a, b;
    for (int i = 0; i < n * 2; ++i) {
        long long x, y; cin >> x >> y;
        if (x == 0)
            a.push_back(abs(y));
        else
            b.push_back(abs(x));
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    ld ans = 1e18;
    for (int t = 0; t < 2; ++t) {
        ld cur = 0;
        for (int i = 0; i < n; ++i)
            cur += sqrt(a[i] * a[i] + b[i] * b[i]);
        ans = min(ans, cur);
        reverse(b.begin(), b.end());
    }
    cout << setprecision(15) << fixed << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
