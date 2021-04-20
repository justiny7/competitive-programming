#include <bits/stdc++.h>
using namespace std;

const int MX = 2e4 + 69;

void solve() {
    int a, b, c, ans = INT_MAX;
    array<int, 3> ret;
    cin >> a >> b >> c;
    for (int na = 1; na < MX; ++na) {
        for (int nb = na; nb < MX; nb += na) {
            int lo = c / nb * nb, hi = lo + nb,
                here = min(ans, abs(na - a) + abs(nb - b) + min(c - lo, hi - c));
            if (here < ans) {
                ans = here;
                ret[0] = na, ret[1] = nb;
                if (c - lo < hi - c)
                    ret[2] = lo;
                else
                    ret[2] = hi;
            }
        }
    }
    cout << ans << '\n';
    cout << ret[0] << " " << ret[1] << " " << ret[2] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
