#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    ll l = a[0];
    for (ll i : a)
        l = lcm(l, i);

    if (find(a.begin(), a.end(), l) != a.end())
        l *= *min_element(a.begin(), a.end());

    map<ll, ll> mp;
    ll x = l;
    for (int i = 2; i <= 1e6; ++i) {
        while (x % i == 0)
            x /= i, ++mp[i];
    }

    ll cnt = 1;
    for (auto [x, c] : mp)
        cnt *= c + 1;

    if (cnt - 2 == n)
        cout << l << '\n';
    else
        cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

