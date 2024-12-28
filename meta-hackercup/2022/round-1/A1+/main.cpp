#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x, --x;
        a[x] = i;
    }
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x, --x;
        b[x] = i;
    }

    int q = (a[0] - b[0] + n) % n;
    for (int i = 1; i < n; ++i) {
        if ((a[i] - b[i] + n) % n != q) {
            cout << "NO\n";
            return;
        }
    }

    if (n == 2) {
        if ((q & 1) != (k & 1))
            cout << "NO\n";
        else
            cout << "YES\n";
        return;
    }

    if (q == 0) {
        if (k == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    } else {
        if (k == 0)
            cout << "NO\n";
        else
            cout << "YES\n";
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

