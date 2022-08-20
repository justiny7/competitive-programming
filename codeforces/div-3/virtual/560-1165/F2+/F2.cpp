#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 2e5 + 69;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    ll tot = 0;
    vector<int> need(n);
    for (int &i : need)
        cin >> i, tot += i;

    vector<vector<int>> offers(n);
    while (m--) {
        int d, t;
        cin >> d >> t, --t, --d;
        offers[t].push_back(d);
    }

    for (int i = 0; i < n; ++i)
        sort(offers[i].begin(), offers[i].end());
    
    auto ok = [&](ll x) -> bool {
        vector<int> here = need;
        vector<vector<int>> take(N);

        for (int i = 0; i < n; ++i) {
            if (!need[i])
                continue;

            auto it = lower_bound(offers[i].begin(), offers[i].end(), x);
            if (it != offers[i].begin())
                take[*prev(it)].push_back(i);
        }

        int cur = 0;
        for (int i = 0; i < min(N, (int)x); ++i) {
            ++cur;

            for (int q : take[i]) {
                int k = min(cur, here[q]);
                cur -= k;
                here[q] -= k;
            }
        }

        cur += max(0LL, x - N);

        int left = accumulate(here.begin(), here.end(), 0);
        // cout << x << " " << left << " " << cur << '\n';
        return left * 2 <= cur;
    };

    ll lo = 0, hi = tot * 2 + 69;
    while (lo < hi) {
        ll mid = lo + hi >> 1;

        if (ok(mid))
            hi = mid;
        else
            lo = mid + 1;
    }

    cout << lo << '\n';
}

