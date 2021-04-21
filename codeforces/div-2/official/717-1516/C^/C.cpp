#include <bits/stdc++.h>
using namespace std;

const int N = 101, A = 2e5 + 69;
int n, a[N], dp[A];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    int g = -1, s = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i], s += a[i];
        if (g < 0)
            g = a[i];
        else
            g = gcd(g, a[i]);
    }
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = A - 1; ~j; --j)
            if (j - a[i] >= 0)
                dp[j] |= dp[j - a[i]];
    if ((s & 1) || !dp[s / 2]) {
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if ((a[i] / g) & 1) {
            cout << "1\n"  << i + 1 << '\n';
            return 0;
        }
    }
    assert(false);
}
