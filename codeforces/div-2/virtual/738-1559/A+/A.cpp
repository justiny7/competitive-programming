#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, cur = INT_MAX;
    cin >> n;

    while (n--) {
        int x;
        cin >> x;
        cur &= x;
    }

    cout << cur << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

