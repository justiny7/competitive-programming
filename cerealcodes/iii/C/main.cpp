#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> p(n), pref(n + 1);
    for (ll &i : p) {
        cin >> i;
    }

    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + p[i];
    }

    auto sum = [&](int l, int r) -> ll {
        if (l > r) {
            return 0;
        }
        return pref[r] - pref[l - 1];
    };
    auto get = [&](int st, int opp) {
        ll add = p[st - 1];
        if (st > opp) {
            swap(st, opp);
        }

        return add + max(sum(st + 1, opp - 1), sum(1, st - 1) + sum(opp + 1, n));
    };

    ll res = 0;
    for (int st = 1, opp = 1; st <= n; st++) {
        while (get(st, opp) > get(st, opp % n + 1)) {
            opp = opp % n + 1;
        }

        res = max(res, get(st, opp));
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

