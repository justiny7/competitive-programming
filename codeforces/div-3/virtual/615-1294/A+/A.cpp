#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    int tot = a + b + c + n;
    if (tot % 3) {
        cout << "NO\n";
        return;
    }

    tot /= 3;
    if (max({a, b, c}) > tot)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

