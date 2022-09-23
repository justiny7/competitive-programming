#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    a = abs(a - 1);
    b = abs(b - c) + abs(c - 1);

    if (a < b)
        cout << 1 << '\n';
    else if (a > b)
        cout << 2 << '\n';
    else
        cout << 3 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

