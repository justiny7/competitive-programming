#include <bits/stdc++.h>
using namespace std;

char g[3][3];
bool check(char c) {
    if (g[0][0] == c && g[0][1] == c && g[0][2] == c)
        return 1;
    if (g[1][0] == c && g[1][1] == c && g[1][2] == c)
        return 1;
    if (g[2][0] == c && g[2][1] == c && g[2][2] == c)
        return 1;
    if (g[0][0] == c && g[1][0] == c && g[2][0] == c)
        return 1;
    if (g[0][1] == c && g[1][1] == c && g[2][1] == c)
        return 1;
    if (g[0][2] == c && g[1][2] == c && g[2][2] == c)
        return 1;
    if (g[0][0] == c && g[1][1] == c && g[2][2] == c)
        return 1;
    if (g[0][2] == c && g[1][1] == c && g[2][0] == c)
        return 1;
    return 0;
}

void solve() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> g[i][j];

    if (check('X'))
        cout << "X\n";
    else if (check('O'))
        cout << "O\n";
    else if (check('+'))
        cout << "+\n";
    else
        cout << "DRAW\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

