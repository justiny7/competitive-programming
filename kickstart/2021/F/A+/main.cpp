#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> pos;
    for (int i = 0; i < n; ++i)
        if (s[i] == '1')
            pos.push_back(i);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1')
            continue;

        auto lo = lower_bound(pos.begin(), pos.end(), i);
        auto hi = lower_bound(pos.begin(), pos.end(), i);

        ll here = INT_MAX;
        if (lo != pos.begin())
            here = min(here, 1LL * abs(i - *prev(lo)));
        if (hi != pos.end())
            here = min(here, 1LL * abs(i - *hi));

        ans += here;
    }

    cout << ans << '\n';
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

