#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long n, m, x;
    cin >> n >> m >> x, --x;
    int c = x / n, r = x % n;
    cout << c + r * m + 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
