#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll m, d;
    cin >> n >> m >> d;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    ll res = 0, sum = 0;
    multiset<ll> ms;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= 0)
            continue;

        if (ms.size() < m) {
            ms.insert(a[i]);
            sum += a[i];
        } else{
            if (a[i] > *ms.begin()) {
                sum -= *ms.begin();
                ms.erase(ms.begin());
                sum += a[i];
                ms.insert(a[i]);
            }
        }

        res = max(res, sum - d * (i + 1));
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

