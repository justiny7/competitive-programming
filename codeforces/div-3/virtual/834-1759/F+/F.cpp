#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, p;
    cin >> n >> p;

    vector<ll> a(n);
    set<ll> have;
    for (ll &i : a)
        cin >> i, have.insert(i);

    int res = p, orig = a.back();
    while (res && have.count(a.back())) {
        (a.back() += p - 1) %= p;
        --res;
    }

    bool f = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] != p - 1) {
            f = 1;
            have.insert(a[i] + 1);
            break;
        }
        have.insert(0);
    }

    if (!f)
        have.insert(1);

    int res2 = p;
    while (orig && have.count(orig))
        --res2, --orig;

    cout << min(res, res2) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

