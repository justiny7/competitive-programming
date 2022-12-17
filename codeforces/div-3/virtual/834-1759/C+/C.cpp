#include <bits/stdc++.h>
using namespace std;

void solve() {
    int l, r, x, a, b;
    cin >> l >> r >> x >> a >> b;

    if (a == b)
        cout << "0\n";
    else if (abs(a - b) >= x)
        cout << "1\n";
    else if ((abs(a - l) >= x && abs(l - b) >= x) || (abs(a - r) >= x && abs(r - b) >= x))
        cout << "2\n";
    else if ((abs(a - r) >= x && abs(r - l) >= x && abs(l - b) >= x) ||
             (abs(a - l) >= x && abs(l - r) >= x && abs(r - b) >= x))
        cout << "3\n";
    else
        cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

