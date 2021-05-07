#include <bits/stdc++.h>
using namespace std;

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int ret; cin >> ret;
    return ret;
}
void guess(int x) {
    cout << "! " << x << endl;
}

int main() {
    int n, t, k;
    cin >> n >> t >> k;
    int lo = 1, hi = n;
    while (lo < hi) {
        int m = lo + hi >> 1;
        if (m - query(1, m) >= k)
            hi = m;
        else
            lo = m + 1;
    }
    guess(lo);
}
