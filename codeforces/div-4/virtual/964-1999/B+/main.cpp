#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    int res = 0;
    for (int i : {a1, a2}) {
        for (int j : {b1, b2}) {
            int k = a1 + a2 - i, l = b1 + b2 - j;
            int q = (i > j) + (k > l);
            int p = (j > i) + (l > k);
            res += (q > p);
        }
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

