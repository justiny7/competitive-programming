#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    double l = 0, r = 1e15;
    bool f = 0;
    for (int i = 1; i <= n; i++) {
        int lo, hi;
        cin >> lo >> hi;

        double lb = 1.0 * i / hi,
               rb = (lo == 0 ? 1e12 : 1.0 * i / lo);

        // cout << "! " << i << " " << lb << " " << rb << '\n';

        if (lb > r || rb < l) {
            f = 1;
        } else {
            l = max(l, lb);
            r = min(r, rb);
        }
    }

    if (f) {
        cout << "-1\n";
    } else {
        cout << setprecision(6) << fixed << l << '\n';
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}
