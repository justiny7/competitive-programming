#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> pos(1001, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i + 1;
    }

    int res = -1;
    for (int i = 1; i <= 1000; ++i)
        for (int j = 1; j <= 1000; ++j)
            if (gcd(i, j) == 1 && ~pos[j] && ~pos[i])
                res = max(res, pos[i] + pos[j]);

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}

