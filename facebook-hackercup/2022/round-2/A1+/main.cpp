#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.size();

    vector<vector<int>> pref(26, vector<int>(n + 1));
    vector<vector<int>> pos(26);
    for (int i = 0; i < n; ++i) {
        pos[s[i] - 'a'].push_back(i + 1);
        for (int j = 0; j < 26; ++j)
            pref[j][i + 1] += pref[j][i] + ((s[i] - 'a') == j);
    }

    int res = 0;

    auto ok = [&](int l, int r, int rem) {
        int m = l + r >> 1; // last element of first half
        if (rem >= m)
            --m;

        int o = (s[rem - 1] - 'a');
        for (int i = 0; i < 26; ++i) {
            int bef = pref[i][m] - pref[i][l - 1];
            int aft = pref[i][r] - pref[i][m];

            if (i == o) {
                if (rem < (l + r >> 1))
                    --bef;
                else
                    --aft;
            }

            if (bef != aft)
                return 0;
        }

        return 1;
    };

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;

        if ((r - l) & 1)
            continue;

        int o = -1;
        for (int i = 0; i < 26; ++i) {
            if ((pref[i][r] - pref[i][l - 1]) & 1) {
                if (o < 0)
                    o = i;
                else {
                    o = -1;
                    break;
                }
            }
        }

        if (o < 0)
            continue;

        // cout << "trying to remove " << o << '\n';

        int fst = *lower_bound(pos[o].begin(), pos[o].end(), l);
        int lst = *prev(upper_bound(pos[o].begin(), pos[o].end(), r));

        if (ok(l, r, fst) || ok(l, r, lst))
            ++res;
    }

    cout << res << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

