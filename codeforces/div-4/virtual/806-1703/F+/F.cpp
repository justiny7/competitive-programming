#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<array<int, 2>> v;
    for (int i = 0; i < n; ++i)
        if (i + 1 > a[i])
            v.push_back({a[i], i + 1});

    sort(v.begin(), v.end());

    ll res = 0;
    int sz = v.size();
    for (int i = 0; i < sz; ++i) {
        int ind = v[i][1];

        int above = v.end() - upper_bound(v.begin(), v.end(), array<int, 2>{ind, INT_MAX});
        res += above;

        // cout << i << " " << v[i][0] << " " << v[i][1] << " " << above << '\n';
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


