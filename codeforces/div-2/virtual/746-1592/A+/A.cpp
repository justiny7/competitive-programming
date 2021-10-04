#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, h;
    cin >> n >> h;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    sort(a.rbegin(), a.rend());
    ll tot = a[0] + a[1];

    ll moves = (h + tot - 1) / tot;
    h -= moves * tot;

    moves *= 2;
    if (h + a[1] <= 0)
        --moves;

    cout << moves << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

