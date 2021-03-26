#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].first;
    for (int i = 0; i < n; ++i)
        cin >> a[i].second;
    sort(a.begin(), a.end());
    int x = 1, y = 1, ans = 0;
    for (int i = 0; i < n; ++i) {
        auto [nx, ny] = a[i];
        if (ny - y == nx - x)
            ans += ((x + y) & 1) ? 0 : ny - y;
        else {
            int len = nx - x - ny + y;
            ans += len / 2;
            if (((x + y) & 1) && (len & 1))
                ++ans;
        }
        x = nx, y = ny;
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
