#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    ll tot = 0, cnt = 0, mn = 1e9 + 30;
    for (ll &i : a) {
        cin >> i;
        tot += abs(i);
        cnt += (i < 0);
        mn = min(mn, abs(i));
    }

    if (cnt & 1)
        cout << tot - mn * 2 << '\n';
    else
        cout << tot << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

