#include <bits/stdc++.h>
using namespace std;

void solve() {
    char g[8][8];
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            cin >> g[i][j];

    for (int i = 0; i < 8; ++i) {
        string s;
        for (int j = 0; j < 8; ++j)
            s += g[j][i];
        
        if (s != "........") {
            for (char c : s)
                if (c != '.')
                    cout << c;
            cout << '\n';
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

