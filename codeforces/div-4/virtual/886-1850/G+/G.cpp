#include <bits/stdc++.h>
using namespace std;

void solve() {
    map<int, int> ver, hor, d1, d2;
    int n;
    cin >> n;

    while (n--) {
        int x, y;
        cin >> x >> y;

        ++ver[x], ++hor[y];
        ++d1[x + y], ++d2[x - y];
    }

    long long res = 0;
    for (auto [x, c] : ver)
        res += 1LL * c * (c - 1);
    for (auto [x, c] : hor)
        res += 1LL * c * (c - 1);
    for (auto [x, c] : d1)
        res += 1LL * c * (c - 1);
    for (auto [x, c] : d2)
        res += 1LL * c * (c - 1);

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

