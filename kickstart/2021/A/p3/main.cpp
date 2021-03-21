#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 301, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int r, c;
ll a[mxN][mxN];
bool vis[mxN][mxN];

bool in(int y, int x) {
    return (y > 0 && x > 0 && y <= r && x <= c);
}

void solve() {
    cin >> r >> c;
    priority_queue<array<ll, 3>> pq;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> a[i][j];
            pq.push({a[i][j], i, j});
            vis[i][j] = 0;
        }
    }
    ll ans = 0;
    while (pq.size()) {
        auto [d, cr, cc] = pq.top();
        pq.pop();
        if (vis[cr][cc])
            continue;
        vis[cr][cc] = 1;
        ans += d - a[cr][cc];
        a[cr][cc] = d;
        if (d <= 1)
            continue;
        for (int i = 0; i < 4; ++i) {
            int nr = cr + dy[i], nc = cc + dx[i];
            if (in(nr, nc) && !vis[nr][nc])
                pq.push({d - 1, nr, nc});
        }
    }
    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}
