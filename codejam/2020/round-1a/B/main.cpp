#include <bits/stdc++.h>
using namespace std;

int cnt(int x) {
    int ret = 0;
    for (int i = 0; i < 31; ++i)
        if ((x & (1 << i)) == 0)
            ++ret;
    return ret;
}

void solve() {
    int n; cin >> n;
    if (n <= 500) {
        for (int i = 1; i <= n; ++i)
            cout << i << " 1\n";
        return;
    }
    int x = n, c = 1;
    while (n - (x + cnt(x)) < 0 || n - (x + cnt(x)) > 31)
        --x;
    vector<pair<int, int>> ans;
    for (int i = 1; i <= 31; ++i) {
        if (x & (1 << (i - 1))) {
            if (c == 1) {
                for (int k = 1; k <= i; ++k)
                    ans.emplace_back(i, k);
                c = i;
            }
            else {
                for (int k = i; k; --k)
                    ans.emplace_back(i, k);
                c = 1;
            }
        }
        else {
            if (c == 1)
                ans.emplace_back(i, c);
            else
                ans.emplace_back(c = i, i);
        }
    }
    for (int i = 0; i < n - (x + cnt(x)); ++i)
        ans.emplace_back(32 + i, (c == 1 ? 1 : 32 + i));
    assert(ans.size() <= 500);
    for (auto [u, v] : ans)
        cout << u << " " << v << '\n';
    cout << ans.size() << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ":\n";
        solve();
    }
}
