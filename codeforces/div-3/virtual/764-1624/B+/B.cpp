#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c)
        cout << "YES\n";
    else if ((a + (b - a) * 2) > 0 && (a + (b - a) * 2) % c == 0)
        cout << "YES\n";
    else if ((a + c) % 2 == 0 && ((a + c) / 2) % b == 0)
        cout << "YES\n";
    else if ((c - (c - b) * 2) > 0 && (c - (c - b) * 2) % a == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

