#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int len = n + m - 1;
    int mn = min(a, b) / len;

    if (mn == 0) {
        cout << "Impossible\n";
        return;
    }

    cout << "Possible\n";

    int ovr = a - mn * len;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int here = mn;
            if (i == 0 && j == 0)
                here += a - mn * len;
            else if (i == 0 && j == m - 1)
                here += b - mn * len;

            cout << here << " \n"[j == m - 1];
        }
    }
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

