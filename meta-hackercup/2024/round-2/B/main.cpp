#include <bits/stdc++.h>
using namespace std;

const int dr[] = {1, 1, 0, 1}, dc[] = {0, 1, 1, -1};
char g[6][7];

void solve() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 7; j++) {
            set<char> cur;
            int r = i, c = j;
            bool f = 0;
            for (int k = 0; k < 4; k++) {
                int turns = 0;
                cur.insert(g[r][c]);
                r += dr[k], c += dc[k];

                if (r < 0 || r >= 6 || c < 0 || c >= 7) {
                    f = 1;
                    break;
                }
            }

            if (!f && cur.size() == 1) {
                ;
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}
