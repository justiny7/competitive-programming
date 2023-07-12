#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, x1, y1, x2, y2;
    string d;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2 >> d;

    if (x1 == x2 && y1 == y2) {
        cout << "0\n";
        return;
    }

    int dx, dy;
    if (d == "DR")
        dx = 1, dy = 1;
    else if (d == "DL")
        dx = 1, dy = -1;
    else if (d == "UL")
        dx = -1, dy = -1;
    else
        dx = -1, dy = 1;

    auto dir = [&]() {
        if (dx == 1 && dy == 1)
            return 0;
        else if (dx == 1 && dy == -1)
            return 1;
        else if (dx == -1 && dy == -1)
            return 2;
        else
            return 3;
    };

    vector<vector<vector<int>>> g(n + 1, vector<vector<int>>(m + 1, vector<int>(4)));
    g[x1][y1][dir()] = 1;
    int ans = 0;
    while (1) {
        bool f = 0;
        if (x1 + dx < 1 || x1 + dx > n)
            dx *= -1, f = 1;
        if (y1 + dy < 1 || y1 + dy > m)
            dy *= -1, f = 1;

        ans += f;
        x1 += dx, y1 += dy;

        if (x1 == x2 && y1 == y2) {
            cout << ans << '\n';
            return;
        }

        if (g[x1][y1][dir()])
            break;
        g[x1][y1][dir()] = 1;
    }

    cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

