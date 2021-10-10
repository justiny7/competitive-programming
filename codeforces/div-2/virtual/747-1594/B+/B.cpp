#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MOD = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;

    ll p = 1, ret = 0;
    for (int i = 0; i < 31; ++i) {
        if (k & (1 << i))
            (ret += p) %= MOD;
        (p *= n) %= MOD;
    }

    cout << ret << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

