#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, c;
    cin >> n >> c;

    vector<ll> v(n);
    for (ll &i : v)
        cin >> i;

    vector<ll> cost;
    for (int i = 0; i < n; ++i)
        cost.push_back(v[i] + i + 1);
    sort(cost.begin(), cost.end());

    ll cur = 0, res = 0;
    for (; res < n; ++res) {
        if (cur + cost[res] > c)
            break;
        cur += cost[res];
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

