#include <bits/stdc++.h>
using namespace std;

void solve() {
    int lo = 2, hi = 999, best = -1;
    while (lo <= hi) {
        int m1 = lo + (hi - lo) / 3,
            m2 = hi - (hi - lo) / 3;

        cout << "? " << m1 << " " << m2 << endl;
        int res;
        cin >> res;

        if (res == m1 * m2) {
            lo = m2 + 1;
        } else if (res == (m2 + 1) * m1) {
            lo = m1 + 1;
            best = m2;
            hi = m2 - 1;
        } else {
            best = m1;
            hi = m1 - 1;
        }
    }

    cout << "! " << best << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

