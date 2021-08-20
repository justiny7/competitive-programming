#include <bits/stdc++.h>
using namespace std;

void solve() {
    int k;
    cin >> k;

    int sq = 1;
    while (sq * sq < k)
        ++sq;

    int dif = sq * sq - k;
    // cout << " " << dif << '\n';

    if (dif < sq - 1)
        cout << sq << " " << dif + 1 << '\n';
    else
        cout << sq - (dif - sq + 1) << " " << sq << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

