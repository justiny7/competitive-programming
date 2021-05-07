#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e3 + 69, dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n, m, a[N][N];
ll w, d[2][N][N];
queue<pair<int, int>> q;

bool in(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);
}

void bfs(int x) {
    while (q.size()) {
        auto [r, c] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (in(nr, nc) && d[x][nr][nc] == INF && ~a[nr][nc]) {
                d[x][nr][nc] = d[x][r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }
}

int main() {
    memset(d, 0x3f, sizeof(d));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> w;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> a[i][j];
    q.emplace(0, 0);
    d[0][0][0] = 0;
    bfs(0);
    q.emplace(n - 1, m - 1);
    d[1][n - 1][m - 1] = 0;
    bfs(1);
    ll ans = INF, smn = INF, emn = INF;
    if (d[1][0][0] != INF)
        ans = d[1][0][0] * w;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] > 0) {
                if (d[0][i][j] != INF)
                    smn = min(smn, d[0][i][j] * w + a[i][j]);
                if (d[1][i][j] != INF)
                    emn = min(emn, d[1][i][j] * w + a[i][j]);
            }
        }
    }
    ans = min(ans, smn + emn);
    if (ans >= INF)
        cout << "-1\n";
    else
        cout << ans << '\n';
}
