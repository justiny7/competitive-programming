#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 998'244'353;

void solve() {
    ll w, g, l;
    cin >> w >> g >> l;

    ll diff = (w - g) % MOD;

    cout << (diff * ((l * 2 + 1) % MOD)) % MOD << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}
