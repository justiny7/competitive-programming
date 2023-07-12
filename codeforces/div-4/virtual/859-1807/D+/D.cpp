#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;

        if ((a[n] - (a[r] - a[l - 1]) + (k * 1LL * (r - l + 1))) & 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

