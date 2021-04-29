#include <bits/stdc++.h>
using namespace std;

//0: rook   1: biship   2: knight
const int N = 11, dr[] = {1, 2, 2, 1, -1, -2, -2, -1}, dc[] = {2, 1, -1, -2, -2, -1, 1, 2};
const pair<int, int> Q = {69420, 69420}, S = {1, 1}, G = {1, 0};
int n, a[N][N];
pair<int, int> st[N * N], dp[N * N][3], d[3][N][N];
priority_queue<pair<pair<int, int>, array<int, 3>>, vector<pair<pair<int, int>, array<int, 3>>>, greater<>> q;

pair<int, int> add(pair<int, int> a, pair<int, int> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

bool in(int r, int c) {
    return (r >= 0 && c >= 0 && r < n && c < n);
}
void dijk() {
    while (q.size()) {
        auto [qq, rr] = q.top(); q.pop();
        auto [r, c, t] = rr;
        if (d[t][r][c] != qq)
            continue;
        if (t == 0) {
            for (int i = 0; i < n; ++i) {
                if (d[t][i][c] > add(d[t][r][c], G)) {
                    d[t][i][c] = add(d[t][r][c], G);
                    q.emplace(d[t][i][c], array<int, 3> {i, c, t});
                }
                if (d[t][r][i] > add(d[t][r][c], G)) {
                    d[t][r][i] = add(d[t][r][c], G);
                    q.emplace(d[t][r][i], array<int, 3> {r, i, t});
                }
            }
        }
        else if (t == 1) {
            for (int i = -n; i < n; ++i) {
                int nr = r + i, nc = c + i;
                if (in(nr, nc) && d[t][nr][nc] > add(d[t][r][c], G)) {
                    d[t][nr][nc] = add(d[t][r][c], G);
                    q.emplace(d[t][nr][nc], array<int, 3> {nr, nc, t});
                }
                nr = r - i;
                if (in(nr, nc) && d[t][nr][nc] > add(d[t][r][c], G)) {
                    d[t][nr][nc] = add(d[t][r][c], G);
                    q.emplace(d[t][nr][nc], array<int, 3> {nr, nc, t});
                }
            }
        }
        else {
            for (int i = 0; i < 8; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (in(nr, nc) && d[t][nr][nc] > add(d[t][r][c], G)) {
                    d[t][nr][nc] = add(d[t][r][c], G);
                    q.emplace(d[t][nr][nc], array<int, 3> {nr, nc, t});
                }
            }
        }
        for (int nt = 0; nt < 3; ++nt) {
            if (nt == t)
                continue;
            if (d[nt][r][c] > add(d[t][r][c], S)) {
                d[nt][r][c] = add(d[t][r][c], S);
                q.emplace(d[nt][r][c], array<int, 3> {r, c, nt});
            }
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            st[a[i][j]] = {i, j};
        }
    }
    for (int t = 1; t < n * n; ++t) {
        auto [r, c] = st[t];
        auto [nr, nc] = st[t + 1];
        for (int i = 0; i < 3; ++i)
            dp[t + 1][i] = Q;
        for (int i = 0; i < 3; ++i) {
            for (int l = 0; l < 3; ++l)
                for (int j = 0; j < n; ++j)
                    for (int k = 0; k < n; ++k)
                        d[l][j][k] = Q;
            d[i][r][c] = {0, 0};
            q.emplace(d[i][r][c], array<int, 3> {r, c, i});
            dijk();
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    pair<int, int> ret = add(dp[t][j], d[k][nr][nc]);
                    if (j != i)
                        ret = add(ret, S);
                    dp[t + 1][k] = min(dp[t + 1][k], ret);
                }
            }
        }
    }
    pair<int, int> ans = min({dp[n * n][0], dp[n * n][1], dp[n * n][2]});
    cout << ans.first << " " << ans.second << '\n';
}
