#include <bits/stdc++.h>
using namespace std;

const int N = 101, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int n, m, sr, sc, d[N][N];
string s[N];

int main() {
    memset(d, -1, sizeof(d));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        for (int j = 0; j < m; ++j)
            if (s[i][j] == 'P')
                sr = i, sc = j;
    }
    queue<pair<int, int>> q;
    d[sr][sc] = 0;
    q.emplace(sr, sc);
    while (q.size()) {
        auto [r, c] = q.front(); q.pop();
        if (s[r][c] == 'O') {
            cout << d[r][c] << '\n';
            return 0;
        }
        for (int i = 0; i < 4; ++i) {
            int nr = (r + dy[i] + n) % n, nc = (c + dx[i] + m) % m;
            if (s[nr][nc] != '#' && d[nr][nc] < 0) {
                d[nr][nc] = d[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }
    cout << "-1\n";
}
