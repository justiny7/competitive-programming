#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    for (int i = 3; i <= n; ++i) {
        int a = i, left = n - i, b, c;

        if (left & 1)
            b = left / 2 + 1, c = left / 2;
        else
            b = left / 2 + 1, c = left / 2 - 1;

        if (a > b && b > c && c > 0) {
            cout << b << " " << a << " " << c << '\n';
            break;
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

