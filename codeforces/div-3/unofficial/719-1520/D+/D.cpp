#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        map<int, ll> mp;
        for (int i = 0; i < n; ++i)
            ++mp[a[i] - i];
        ll ans = 0;
        for (auto [p, v] : mp)
            ans += (v * (v - 1) / 2);
        cout << ans << '\n';
    }
}
