#include <bits/stdc++.h>
using namespace std;

/*
....
.**.
.*..
...
*/

vector<pair<pair<int, int>, char>> ops = {
    {{0, 0}, '*'},
    {{1, 0}, '*'},
    {{0, 1}, '*'},
    {{-1, -1}, '.'},
    {{-1, 0}, '.'},
    {{-1, 1}, '.'},
    {{-1, 2}, '.'},
    {{0, -1}, '.'},
    {{0, 2}, '.'},
    {{1, -1}, '.'},
    {{1, 1}, '.'},
    {{1, 2}, '.'},
    {{2, -1}, '.'},
    {{2, 0}, '.'},
    {{2, 1}, '.'}
};

void flip_vert() {
    for (auto &p : ops)
        p.first.first *= -1;
}
void flip_hor() {
    for (auto &p : ops)
        p.first.second *= -1;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> g;
    g.push_back(string(m + 2, '.'));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        s = "." + s + ".";
        g.push_back(s);
    }
    g.push_back(string(m + 2, '.'));

    /*
    for (string s : g)
        cout << s << '\n';
    */

    vector<vector<char>> done(n + 1, vector<char>(m + 1));
    auto check = [&](int i, int j) -> bool {
        for (auto p : ops) {
            auto [di, dj] = p.first;
            int ni = i + di, nj = j + dj;

            if (ni < 0 || ni > n + 1 || nj < 0 || nj > m + 1 || g[ni][nj] != p.second)
                return 0;
        }

        for (auto p : ops) {
            if (p.second == '*') {
                auto [di, dj] = p.first;
                int ni = i + di, nj = j + dj;
                done[ni][nj] = 1;
            }
        }

        return 1;
    };

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] != '*' || done[i][j])
                continue;

            if (check(i, j))
                continue;
            flip_vert();
            if (check(i, j))
                continue;
            flip_hor();
            if (check(i, j))
                continue;
            flip_vert();
            if (check(i, j))
                continue;
            flip_hor();
        }
    }
    
    /*
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cout << (done[i][j] ? '+' : '.') << " \n"[j == m];
    */

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (g[i][j] == '*' && !done[i][j]) {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

