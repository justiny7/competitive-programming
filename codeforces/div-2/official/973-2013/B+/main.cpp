#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> v(n);
    for (ll &i : v) {
        cin >> i;
    }

    for (int i = 0; i < n - 2; i++) {
        v[n - 2] -= v[i];
    }

    cout << v.back() - v[n - 2] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
