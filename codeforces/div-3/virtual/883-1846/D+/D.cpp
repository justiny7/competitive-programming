#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d, h;
    cin >> n >> d >> h;

    vector<int> v(n);
    for (int &i : v)
        cin >> i;

    double res = 0;
    int lst = INT_MAX;
    for (int i = n - 1; ~i; --i) {
        int take = max(0, v[i] + h - lst);
        // cout << "> " << i << " " << take << '\n';
        res += 0.5 * d * h;
        res -= 0.5 * take * (1.0 * take * d / (1.0 * h));
        lst = v[i];
    }

    cout << setprecision(6) << fixed << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

