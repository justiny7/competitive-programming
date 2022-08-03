#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, h, m;
    cin >> n >> h >> m;

    int st = h * 60 + m;

    int res = INT_MAX;
    while (n--) {
        int hh, mm;
        cin >> hh >> mm;

        int here = hh * 60 + mm;
        if (here < st)
            here += 24 * 60;

        res = min(res, here - st);
    }

    cout << res / 60 << " " << res % 60 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

