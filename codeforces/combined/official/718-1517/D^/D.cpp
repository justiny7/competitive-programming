#include <bits/stdc++.h>
using namespace std;

const int N = 501, K = 11;
int n, m, k, d[K][N][N];
vector<array<int, 3>> adj[N][N];

int main() {
    memset(d, 0x3f, sizeof(d));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    if (k & 1) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cout << -1 << " \n"[j == m - 1];
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            int x; cin >> x;
            adj[i][j].push_back({i, j + 1, x});
            adj[i][j + 1].push_back({i, j, x});
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            adj[i][j].push_back({i + 1, j, x});
            adj[i + 1][j].push_back({i, j, x});
        }
    }
    for (int l = 0; l <= k / 2; ++l) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (l == 0)
                    d[l][i][j] = 0;
                else {
                    for (auto [r, c, w] : adj[i][j])
                        d[l][i][j] = min(d[l][i][j], d[l - 1][r][c] + w);
                }
                if (l == k / 2)
                    cout << d[l][i][j] * 2 << " \n"[j == m - 1];
            }
        }
    }
}
