#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 69, dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};
int n, m, dist[2][N][N];
string s[N], ans, dir = "ULDR";
queue<pair<int, int>> q;
vector<pair<int, int>> mon, edge;

bool in(int r, int c) {
    return (r >= 0 && c >= 0 && r < n && c < m);
}
void bfs(int x) {
    while (q.size()) {
        auto [r, c] = q.front(); q.pop();
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i], nc = c + dc[i];
            if (in(nr, nc) && s[nr][nc] != '#' && dist[x][nr][nc] < 0) {
                dist[x][nr][nc] = dist[x][r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }
}
void dfs(int r, int c) {
    if (s[r][c] == 'A')
        return;
    for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i], nc = c + dc[i];
        if (in(nr, nc) && dist[0][nr][nc] + 1 == dist[0][r][c]) {
            ans += dir[i];
            dfs(nr, nc);
        }
    }
}

int main() {
    memset(dist, -1, sizeof(dist));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'A') {
                q.emplace(i, j);
                dist[0][i][j] = 0;
            }
            else if (s[i][j] == 'M')
                mon.emplace_back(i, j);
            if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && s[i][j] != '#')
                edge.emplace_back(i, j);
        }
    }
    bfs(0);
    for (auto [r, c] : mon) {
        dist[1][r][c] = 0;
        q.emplace(r, c);
    }
    bfs(1);
    for (auto [r, c] : edge) {
        if (dist[0][r][c] < 0 || (~dist[1][r][c] && dist[0][r][c] >= dist[1][r][c]))
            continue;
        cout << "YES\n" << dist[0][r][c] << '\n';
        dfs(r, c);
        reverse(ans.begin(), ans.end());
        cout << ans << '\n';
        return 0;
    }
    cout << "NO\n";
}
