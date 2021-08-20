#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int dif = abs(a - b);
    if (max({a, b, c}) > dif * 2) {
        cout << "-1\n";
        return;
    }

    if (c > dif)
        cout << c - dif << '\n';
    else
        cout << c + dif << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

