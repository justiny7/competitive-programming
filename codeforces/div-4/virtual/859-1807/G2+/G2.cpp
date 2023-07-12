#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    if (a[0] != 1) {
        cout << "NO\n";
        return;
    }

    ll s = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] > s) {
            cout << "NO\n";
            return;
        }
        s += a[i];
    }

    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

