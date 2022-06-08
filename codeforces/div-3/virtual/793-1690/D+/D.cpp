#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int cur = 0, res = INT_MAX;
    for (int i = 0; i < k - 1; ++i)
        cur += s[i] == 'B';

    for (int i = k - 1; i < n; ++i) {
        cur += s[i] == 'B';
        res = min(res, k - cur);
        cur -= s[i - k + 1] == 'B';
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

