#include <bits/stdc++.h>
using namespace std;

void solve() {
    int c = 0, a = 0, k;
    cin >> k;

    while (c < k) {
        ++a;
        if (a % 10 != 3 && a % 3 != 0)
            ++c;
    }

    cout << a << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

