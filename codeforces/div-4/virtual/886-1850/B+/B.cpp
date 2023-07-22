#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = 1, mx = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a, b;
        cin >> a >> b;

        if (a <= 10) {
            if (b > mx) {
                mx = b;
                res = i;
            }
        }
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

