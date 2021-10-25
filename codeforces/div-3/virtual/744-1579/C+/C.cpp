#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<char>> g(n, vector<char>(m)), ok(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];

    for (int i = n - 1; ~i; --i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '.')
                continue;

            int c = 0;
            for (; j + c < m && j - c >= 0 && i - c >= 0; ++c)
                if (g[i - c][j - c] == '.' || g[i - c][j + c] == '.')
                    break;

            if (c > k) {
                c = 0;
                for (; j + c < m && j - c >= 0 && i - c >= 0; ++c) {
                    if (g[i - c][j - c] == '.' || g[i - c][j + c] == '.')
                        break;
                    ok[i - c][j - c] = ok[i - c][j + c] = 1;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '*' && !ok[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

