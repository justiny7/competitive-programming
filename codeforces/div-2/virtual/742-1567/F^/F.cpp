#include <bits/stdc++.h>
using namespace std;

const int N = 569;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

int n, m, ans[N][N];
char g[N][N];
vector<array<int, 2>> dif[N][N];

bool in(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}
void dfs(int r, int c, bool f = 0) {
    ans[r][c] = (f ? 1 : 4);
    for (auto [nr, nc] : dif[r][c])
        if (ans[nr][nc] < 0)
            dfs(nr, nc, f ^ 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == '.')
                continue;

            vector<array<int, 2>> here;
            for (int k = 0; k < 4; ++k) {
                int ni = i + dr[k], nj = j + dc[k];
                if (in(ni, nj) && g[ni][nj] == '.')
                    here.push_back({ni, nj});
            }

            int sz = here.size();
            if (sz & 1) {
                cout << "NO\n";
                return 0;
            } else if (sz == 2) {
                dif[here[0][0]][here[0][1]].push_back(here[1]);
                dif[here[1][0]][here[1][1]].push_back(here[0]);
            } else if (sz == 4) {
                dif[here[0][0]][here[0][1]].push_back(here[1]);
                dif[here[1][0]][here[1][1]].push_back(here[0]);
                dif[here[2][0]][here[2][1]].push_back(here[3]);
                dif[here[3][0]][here[3][1]].push_back(here[2]);
            }
        }
    }

    memset(ans, -1, sizeof(ans));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (ans[i][j] < 0 && g[i][j] == '.')
                dfs(i, j);

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (ans[i][j] < 0) {
                ans[i][j] = 0;
                for (int k = 0; k < 4; ++k) {
                    int ni = i + dr[k], nj = j + dc[k];
                    if (in(ni, nj) && g[ni][nj] == '.')
                        ans[i][j] += ans[ni][nj];
                }
            }

            cout << ans[i][j] << " \n"[j == m - 1];
        }
    }
}

