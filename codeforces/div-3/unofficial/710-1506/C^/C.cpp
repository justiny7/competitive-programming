#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size(), ans = INT_MAX;
    for (int len = 0; len <= 20; ++len)
        for (int i = 0; i + len <= n; ++i)
            for (int j = 0; j + len <= m; ++j)
                if (s.substr(i, len) == t.substr(j, len))
                    ans = min(ans, n + m - len * 2);
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
