#include <bits/stdc++.h>
using namespace std;

int f(int a, int b, int c) {
    return max(0, max(b, c) + 1 - a);
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    cout << f(a, b, c) << " " << f(b, a, c) << " " << f(c, a, b) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

