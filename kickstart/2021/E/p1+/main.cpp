#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> s, n = s.size();

    map<char, int> mp;
    for (char c : s)
        ++mp[c];

    for (auto [c, x] : mp) {
        if (x * 2 > n) {
            cout << "IMPOSSIBLE\n";
            return;
        }
    }

    string ans(n, '$');
    for (int i = 0; i < n; ++i) {
        bool f = 0;
        int pos = -1;
        for (int j = 0; j < n; ++j) {
            if (ans[j] == '$' && s[i] != s[j]) {
                ans[j] = s[i];
                f = 1;
                break;
            } else if (ans[j] == '$') {
                pos = j;
            }
        }

        if (!f) {
            assert(~pos);
            for (int j = 0; j < n; ++j) {
                if (ans[j] != '$' && s[i] != s[j] && ans[j] != s[i]) {
                    ans[pos] = s[i];
                    swap(ans[j], ans[pos]);
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

