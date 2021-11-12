#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int z = 0, o = 0;
    while (n--) {
        int x;
        cin >> x;

        if (x == 1)
            ++o;
        if (x == 0)
            ++z;
    }

    long long res = o;
    while (z--)
        res *= 2;
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

