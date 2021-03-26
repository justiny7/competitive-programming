#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        ++mp[x];
    }
    int mx = 0;
    for (auto [x, c] : mp)
        mx = max(mx, c);
    cout << max((n & 1), mx * 2 - n) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
