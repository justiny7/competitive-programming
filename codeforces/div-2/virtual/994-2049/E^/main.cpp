#include <bits/stdc++.h>
using namespace std;

int n;
bool rev = 0;

int query(int l, int r) {
    if (rev) {
        int l0 = n - r + 1;
        int r0 = n - l + 1;
        l = l0, r = r0;
    }

    cout << "? " << l << ' ' << r << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    rev = 0;
    cin >> n;

    int m = n / 2;

    int q = query(1, m);

    int l = 1, r = m;
    if (q == 1) {
        rev = 1;
    }

    int m2 = (l + r) / 2;
    int x = query(l, m2);
    int y = query(m2 + 1, r);

    if (x == y) {
        // one not in this half, k > n / 2
        int lo = n / 2, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (query(n - mid + 1, n) == 0)
                hi = mid;
            else
                lo = mid + 1;
        }

        cout << "! " << lo << endl;
    }
    else {
        // one is in this half, k < n / 2

        int lo = 2, hi = n / 2;
        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (query(n - mid + 1, n) == 1)
                hi = mid;
            else
                lo = mid + 1;
        }

        cout << "! " << lo << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
