#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<vector<char>> g(n, vector<char>(n));
    int tot = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j], tot += g[i][j] - '0';

    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
        int here = 0;
        for (int j = 0; j < n; ++j)
            here += g[j][(i + j) % n] - '0';

        res = min(res, tot - here + n - here);
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

