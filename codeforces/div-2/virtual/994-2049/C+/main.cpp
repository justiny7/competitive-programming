#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y, x--, y--;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i % 2;
    }

    if (n & 1) {
        a.back() = 2;

        if (a[x] == a[y]) {
            if (a[x] == 0) {
                for (int i = 0; i < n - 1; i++) {
                    a[i] ^= 1;
                }
            }

            if (a[(x + n - 1) % n] != 2 && a[(x + 1) % n] != 2) {
                a[x] = 2;
            } else {
                a[y] = 2;
            }
        }

    } else {
        if (a[x] == a[y]) {
            a[x] = 2;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
