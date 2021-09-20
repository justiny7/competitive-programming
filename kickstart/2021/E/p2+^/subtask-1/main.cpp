#include <bits/stdc++.h>
using namespace std;

void solve() {
    int R, C, K;
    int r1, c1, r2, c2;

    cin >> R >> C >> K;
    cin >> r1 >> c1 >> r2 >> c2;

    int len = c2 - c1 + 1, hgt = r2 - r1 + 1;
    
    int ans = (len + 1) * hgt + (hgt + 1) * len;
    if (r1 == 1)
        ans -= len;
    if (r2 == R)
        ans -= len;
    if (c1 == 1)
        ans -= hgt;
    if (c2 == C)
        ans -= hgt;

    int add = min({r1 - 1, R - r2, c1 - 1, C - c2});

    // cout << ans << " " << add << '\n';

    cout << ans + add << '\n';
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

