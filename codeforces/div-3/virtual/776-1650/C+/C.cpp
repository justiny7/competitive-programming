#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> pts(m);
    for (int i = 0; i < m; ++i)
        cin >> pts[i][0] >> pts[i][1], pts[i][2] = i + 1;

    sort(pts.begin(), pts.end(), [&](auto a, auto b) {
        return a[1] < b[1];
    });

    while (pts.size() > n * 2)
        pts.pop_back();

    sort(pts.begin(), pts.end());

    ll res = 0;
    for (auto [x, w, i] : pts)
        res += w;

    cout << res << '\n';
    for (int i = 0; i < n; ++i)
        cout << pts[i][2] << " " << pts[n * 2 - i - 1][2] << '\n';
    
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

