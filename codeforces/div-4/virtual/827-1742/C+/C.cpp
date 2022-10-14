#include <bits/stdc++.h>
using namespace std;

void solve() {
    char g[8][8];
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            cin >> g[i][j];

    for (int i = 0; i < 8; ++i) {
        bool f = 1;
        for (int j = 0; j < 8; ++j)
            f &= g[i][j] == 'R';

        if (f && g[i][0] != '.') {
            cout << g[i][0] << '\n';
            return;
        }
    }

    for (int i = 0; i < 8; ++i) {
        bool f = 1;
        for (int j = 0; j < 8; ++j)
            f &= g[j][i] == 'B';

        if (f && g[0][i] != '.') {
            cout << g[0][i] << '\n';
            return;
        }
    }

    assert(false);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}

