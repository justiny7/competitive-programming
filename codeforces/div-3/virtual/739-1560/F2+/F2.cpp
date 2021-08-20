#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll x, dp[11][1 << 10][2]; // dp[digit][mask][greater]
string s;
int n, k;

ll p10(int x) {
    ll ret = 1;
    while (x--)
        ret *= 10;
    return ret;
}
ll go(int pos = 0, int msk = 0, int big = 0, ll p = p10(n - 1)) {
    if (pos == n)
        return 0;
    if (~dp[pos][msk][big])
        return dp[pos][msk][big];

    ll here = INT_MAX;
    int dig = s[pos] - '0';
    for (int i = big ? 0 : dig; i < 10; ++i) {
        if (!(msk & (1 << i)) && __builtin_popcount(msk) == k)
            continue;

        here = min(here, i * p + go(pos + 1, msk | (1 << i), big | (i > dig), p / 10));
        if (here != INT_MAX)
            break;
    }

    return dp[pos][msk][big] = here;
}
void solve() {
    cin >> x >> k;
    s = to_string(x), n = s.size();

    memset(dp, -1, sizeof(dp));
    cout << go() << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

