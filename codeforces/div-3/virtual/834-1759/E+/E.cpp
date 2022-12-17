#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, h;
    cin >> n >> h;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    vector<ll> perm = {2, 2, 3};
    int res = 0;
    do {
        int ind = 0, here = 0;
        ll cur = h;
        for (int i = 0; i < n; ++i) {
            if (a[i] < cur)
                cur += a[i] / 2, ++here;
            else {
                if (ind == 3)
                    break;

                cur *= perm[ind++];
                --i;
            }
        }

        res = max(res, here);
    } while (next_permutation(perm.begin(), perm.end()));

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

