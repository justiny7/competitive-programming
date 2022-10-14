#include <bits/stdc++.h>
using namespace std;

const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> g(n, vector<char>(m)), no(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];

            if (g[i][j] == '#')
                no[i][j] = 1;
        }
    }

    auto in = [&](int r, int c) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    };
    auto test = [&](int r, int c) {
        int cc = 0;
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            cc += (!in(nr, nc) || no[nr][nc]);
        }

        return (cc > 2);
    };

    queue<array<int, 2>> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (test(i, j)) {
                no[i][j] = 1;
                q.push({i, j});
            }
        }
    }

    while (q.size()) {
        auto [r, c] = q.front();
        q.pop();

        // cout << r << " " << c << '\n';

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (in(nr, nc) && !no[nr][nc] && test(nr, nc)) {
                no[nr][nc] = 1;
                q.push({nr, nc});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (no[i][j] && g[i][j] == '^') {
                cout << "Impossible\n";
                return;
            } else if (!no[i][j]) {
                g[i][j] = '^';
            }
        }
    }

    cout << "Possible\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            cout << g[i][j];
        cout << '\n';
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

