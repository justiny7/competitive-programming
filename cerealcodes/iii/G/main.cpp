#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 3;
int n, m;
vector<vector<int>> dp[4], mp, up, lft;

void rotate(vector<vector<int>> &grid) {
    vector<array<int, 3>> v;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            v.push_back({i, j, grid[i][j]});
        }
    }

    for (auto [x, y, c] : v) {
        grid[y][n + 1 - x] = c;
    }
}

int calc(int x, int y, vector<vector<int>> &dp) {
    if (dp[x][y] != -1) {
        return dp[x][y];
    }

    int res = 1e9;
    if (up[x][y] != -1) {
        res = min(res, calc(up[x][y], y, dp) - up[x][y]);
    }
    if (lft[x][y] != -1) {
        res = min(res, calc(x, lft[x][y], dp) - lft[x][y]);
    }

    return dp[x][y] = x + y + (res == 1e9 ? 0 : res);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;
    mp = up = lft = vector<vector<int>>(n + 2, vector<int>(n + 2));
    for (auto &v : dp) {
        v = vector<vector<int>>(n + 2, vector<int>(n + 2, -1));
    }
    
    while (m--) {
        int x, y;
        cin >> x >> y;
        mp[x][y] = true;
    }

    for (int k = 0; k < 4; k++) {
        for (int i = 0; i <= n; i++) {
            up[i][0] = up[0][i] = lft[i][0] = lft[0][i] = -1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (mp[i - 1][j - 1]) {
                    up[i][j] = i - 1;
                    lft[i][j] = j - 1;
                } else {
                    up[i][j] = max(up[i - 1][j], up[i][j - 1]);
                    lft[i][j] = max(lft[i - 1][j], lft[i][j - 1]);
                }
            }
        }

        for (int i = n; i > 0; i--) {
            for (int j = n; j > 0; j--) {
                if (dp[k][i][j] == -1) {
                    calc(i, j, dp[k]);
                }
            }
        }

        rotate(mp);
        for (int t = 0; t < (4 - k) % 4; t++) {
            rotate(dp[k]);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mp[i][j] += mp[i - 1][j] + mp[i][j - 1] - mp[i - 1][j - 1];
        }
    }

    auto get = [&](int x1, int y1, int x2, int y2) {
        if (x1 > x2 || y1 > y2) {
            return 0;
        }
        return mp[x2][y2] - mp[x1 - 1][y2] - mp[x2][y1 - 1] + mp[x1 - 1][y1 - 1];
    };

    int res = 1e9;
    for (int i = 1; i <= n; i++) {
        int lf = 1e9, rt = 1e9, tp = 1e9, bt = 1e9;

        if (get(1, 1, n, i - 1) == 0) {
            lf = n + 1;
        }
        if (get(1, i + 1, n, n) == 0) {
            rt = n + 1;
        }
        if (get(1, 1, i - 1, n) == 0) {
            tp = n + 1;
        }
        if (get(i + 1, 1, n, n) == 0) {
            bt = n + 1;
        }

        for (int j = 1; j <= n; j++) {
            // vertical i, horizontal j
            lf = min(lf, dp[0][j][i] + dp[1][j][i] - i);
            rt = min(rt, dp[2][j][i] + dp[3][j][i] - (n + 1 - i));

            // horizontal i, vertical j
            tp = min(tp, dp[0][i][j] + dp[3][i][j] - i);
            bt = min(bt, dp[1][i][j] + dp[2][i][j] - (n + 1 - i));
        }


        res = min({res, lf + rt - (n + 1), tp + bt - (n + 1)});
    }

    cout << res << '\n';
}
