#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int x = 0, y = 0;
    for (char c : s) {
        if (c == 'U')
            ++y;
        else if (c == 'D')
            --y;
        else if (c == 'R')
            ++x;
        else
            --x;

        if (x == 1 && y == 1) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

