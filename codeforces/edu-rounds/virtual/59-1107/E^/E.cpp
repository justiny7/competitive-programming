#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 269;
int n; ll a[N], dp[N][N][N];
string s;

ll go(int st = 0, int en = n, int p = 1) {
    if (st >= en)
        return 0;
    if (st + 1 == en)
        return a[p];
    if (~dp[st][en][p])
        return dp[st][en][p];
    ll here = a[p] + go(st + 1, en, 1);
    for (int i = st + 1; i < en; ++i)
        if (s[i] == s[st])
            here = max(here, go(st + 1, i, 1) + go(i, en, p + 1));
    return dp[st][en][p] = here;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cout << go() << '\n';
}
