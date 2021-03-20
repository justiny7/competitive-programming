#include <bits/stdc++.h>
using namespace std;

const int mxV = 2e7 + 1;
int cnt[mxV];

void sieve() {
    for (int i = 2; i < mxV; ++i) {
        if (!cnt[i]) {
            cnt[i] = 1;
            for (int j = i * 2; j < mxV; j += i)
                ++cnt[j];
        }
    }
}

void solve() {
    int c, d, x, ans = 0;
    cin >> c >> d >> x;
    for (int i = 1; i * i <= x; ++i) {
        if (x % i)
            continue;
        int k1 = x / i + d, k2 = i + d;
        if (k1 % c == 0)
            ans += (1 << cnt[k1 / c]);
        if (k2 % c == 0 && i * i != x)
            ans += (1 << cnt[k2 / c]);
    }
    cout << ans << '\n';
}

int main() {
    sieve();
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
