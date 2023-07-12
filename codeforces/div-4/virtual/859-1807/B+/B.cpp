#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int e = 0, o = 0;
    while (n--) {
        int x;
        cin >> x;

        if (x & 1)
            o += x;
        else
            e += x;
    }

    cout << ((e > o) ? "YES" : "NO") << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

