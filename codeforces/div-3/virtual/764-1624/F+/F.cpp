#include <bits/stdc++.h>
using namespace std;

int n;

int query(int c) {
    cout << "+ " << c << endl;

    int res;
    cin >> res;
    return res;
}

int main() {
    cin >> n;

    int cur = 0;

    int lo = 1, hi = n - 1;
    while (lo < hi) {
        int m = lo + hi + 1 >> 1;

        int q = n - m % n;
        int now = query(n - m % n);
        if (now > cur)
            lo = m;
        else
            hi = m - 1;

        cur = now;
        lo += q;
        hi += q;
    }

    cout << "! " << lo << endl;
}

