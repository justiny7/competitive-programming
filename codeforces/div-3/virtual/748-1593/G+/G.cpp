#include <bits/stdc++.h>
using namespace std;

// must be even distance between every [ ] pair
// greedily match alternating parities

void solve() {
    int n, q;
    string s;
    cin >> s >> q, n = s.size();

    vector<vector<int>> pref(2, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '[' || s[i - 1] == ']')
            ++pref[i & 1][i];

        pref[0][i] += pref[0][i - 1];
        pref[1][i] += pref[1][i - 1];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;

        int o = pref[1][r] - pref[1][l - 1], e = pref[0][r] - pref[0][l - 1];
        cout << abs(o - e) << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

