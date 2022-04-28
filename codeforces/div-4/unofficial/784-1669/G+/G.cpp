#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];

    for (int j = 0; j < m; ++j) {
        int cnt = 0, lst = -1;
        for (int i = 0; i < n; ++i) {
            if (g[i][j] == 'o') {
                for (int k = i - 1; k > lst; --k)
                    g[k][j] = '.';
                for (int k = i - 1; cnt > 0; --cnt, --k)
                    g[k][j] = '*';
                lst = i;
            } else if (g[i][j] == '*') {
                ++cnt;
            }
        }

        for (int k = n - 1; k > lst; --k)
            g[k][j] = '.';
        for (int k = n - 1; cnt > 0; --cnt, --k)
            g[k][j] = '*';
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << g[i][j];
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

