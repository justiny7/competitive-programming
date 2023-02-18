#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, c;
    cin >> n >> c;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    vector<array<ll, 2>> cost(n);
    for (int i = 0; i < n; ++i)
        cost[i] = {a[i] + min(i + 1, n - i), i};

    sort(cost.begin(), cost.end());

    vector<int> ind(n);
    vector<ll> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + cost[i][0];
        ind[cost[i][1]] = i + 1;
    }

    auto get = [&](int x, int l, int r) {
        int lo = l, hi = r, res = -1;
        while (lo <= hi) {
            int m = lo + hi >> 1;
            if (pref[m] <= x)
                res = m, lo = m + 1;
            else
                hi = m - 1;
        }
        return res;
    };

    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, get(c - (a[i] + i + 1), 0, ind[i] - 1) + 1);
        res = max(res, get(c + cost[ind[i] - 1][0] - (a[i] + i + 1), ind[i], n));
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

