#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, m;
    cin >> n >> m;

    ll res = 1;
    while (n % 10 == 0)
        n /= 10, res *= 10;
    while (n % 5 == 0 && m >= 2)
        n /= 5, m /= 2, res *= 10;
    while (n % 2 == 0 && m >= 5)
        n /= 2, m /= 5, res *= 10;
    while (m >= 10)
        m /= 10, res *= 10;

    cout << res * n * m << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

