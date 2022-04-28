#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int odd = -1, even = -1;
    bool o = 1, e = 1;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (i & 1) {
            if (odd < 0)
                odd = x & 1;
            else
                o &= odd == (x & 1);
        } else {
            if (even < 0)
                even = x & 1;
            else
                e &= even == (x & 1);
        }
    }

    cout << ((o && e) ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

