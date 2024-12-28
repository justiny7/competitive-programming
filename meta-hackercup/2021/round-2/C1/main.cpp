#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k, --k;

    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];

    int ans = INT_MAX;
    vector<vector<int>> pref(n, vector<int>(m));
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pref[i][j] = g[i][j] == '.';
                if (i)
                    pref[i][j] += pref[i - 1][j];
            }
        }

        for (int i = k; i < n; ++i) {
            int rem = 0;
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 'X')
                    ++rem;
                else if (i > k)
                    rem += (i - k) > pref[i - 1][j];
            }

            ans = min(ans, rem + i - k);
        }

        int tp = 0;
        for (int j = 0; j < m; ++j)
            tp += (n - k) > pref[n - 1][j];
        ans = min(ans, tp + n - k);

        for (int i = 0; i < n / 2; ++i)
            swap(g[i], g[n - i - 1]);
        k = n - k - 1;
    }

    cout << ans << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

