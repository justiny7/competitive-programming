#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

void solve() {
    int n, m, p = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c; cin >> c;
            p += (c == '#');
        }
    }
    int ans = 1;
    for (int i = 0; i < p; ++i)
        ans = ans * 2 % M;
    if (p == n * m)
        ans = (ans - 1 + M) % M;
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
