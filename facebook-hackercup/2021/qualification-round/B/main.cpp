#include <bits/stdc++.h>
using namespace std;

const int N = 69;
int n;
char g[N][N];
bool seen[N][N];

void solve() {
    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];

    memset(seen, 0, sizeof(seen));

    map<int, int> ans;
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < n; ++i) {
            int here = 0;
            bool f = 1;

            for (int j = 0; j < n; ++j) {
                f &= (g[i][j] != 'O');
                here += (g[i][j] == '.');
            }

            if (!f)
                here = INT_MAX;

            if (here > 1)
                ++ans[here];
            else {
                int row = i, col = 0;
                for (; col < n; ++col)
                    if (g[i][col] == '.')
                        break;

                if (t == 1)
                    swap(row, col);

                if (!seen[row][col]) {
                    seen[row][col] = 1;
                    ++ans[here];
                }
            }
        }

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (i < j)
                    swap(g[i][j], g[j][i]);
    }

    auto it = ans.begin();
    if (it->first == INT_MAX)
        cout << "Impossible\n";
    else
        cout << it->first << " " << it->second << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

