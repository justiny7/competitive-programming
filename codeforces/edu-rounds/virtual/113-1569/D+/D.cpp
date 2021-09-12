#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void go(int x, int y, vector<int> &v, vector<map<int, int>> &c) {
    auto lo = lower_bound(v.begin(), v.end(), x);
    if (*lo > x)
        ++c[lo - v.begin() - 1][y];
}
ll get(vector<map<int, int>> &v) {
    ll ret = 0;

    for (auto q : v) {
        ll here = 0;
        for (auto [c, x] : q)
            here += x;

        here = here * (here - 1) / 2;

        for (auto [c, x] : q)
            here -= 1LL * x * (x - 1) / 2;

        ret += here;
    }

    return ret;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> vx(n), vy(m);
    for (int &i : vx)
        cin >> i;
    for (int &i : vy)
        cin >> i;

    vector<map<int, int>> cx(n), cy(m);
    while (k--) {
        int x, y;
        cin >> x >> y;

        go(x, y, vx, cx);
        go(y, x, vy, cy);
    }

    cout << get(cx) + get(cy) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

