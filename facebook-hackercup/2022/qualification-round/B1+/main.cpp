#include <bits/stdc++.h>
using namespace std;

const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m));
    int c = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j], c += g[i][j] == '^';

    if (n == 1 || m == 1) {
        if (c)
            cout << "Impossible\n";
        else {
            cout << "Possible\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j)
                    cout << g[i][j];
                cout << '\n';
            }
        }
    } else {
        cout << "Possible\n";
        for (int i = 0; i < n; ++i)
            cout << string(m, '^') << '\n';
    }
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

