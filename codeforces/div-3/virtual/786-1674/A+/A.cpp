#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    if (y % x)
        cout << "0 0\n";
    else {
        int q = y / x;

        if (q == 1)
            cout << "1 1\n";
        else {
            for (int a = 2; a <= 100; ++a) {
                int p = q, c = 0;
                while (p % a == 0)
                    p /= a, ++c;

                if (p == 1) {
                    cout << c << " " << a << '\n';
                    return;
                }
            }

            cout << "0 0\n";
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

