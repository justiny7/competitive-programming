#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

const int N = 3e3 + 69;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];

    vector<ll> x_contrib(N), y_contrib(N);
    for (int i = 0; i < N; ++i) {
        ll xc = 0, yc = 0;
        for (int j = 0; j < n; ++j) {
            (xc += 1LL * (i - a[j]) * (i - a[j])) %= MOD;
            (yc += 1LL * (i - b[j]) * (i - b[j])) %= MOD;
        }

        x_contrib[i] = xc;
        y_contrib[i] = yc;
    }

    ll res = 0;

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;

        (res += (x_contrib[x] + y_contrib[y]) % MOD) %= MOD;
    }

    cout << res << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

