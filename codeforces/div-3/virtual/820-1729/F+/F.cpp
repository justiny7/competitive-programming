#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    int w, m;
    cin >> s >> w >> m;

    int n = s.size();

    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i)
        pref[i + 1] = pref[i] + (s[i] - '0');

    vector<int> pos[9];
    for (int i = 0; i + w <= n; ++i) {
        int c = pref[i + w] - pref[i];
        pos[c % 9].push_back(i + 1);
    }

    while (m--) {
        int l, r, k;
        cin >> l >> r >> k;

        int c = (pref[r] - pref[l - 1]) % 9;
        int L = INT_MAX, R = INT_MAX;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if ((i * c + j) % 9 != k)
                    continue;

                if (i == j) {
                    if (pos[i].size() >= 2) {
                        int cl = pos[i][0], cr = pos[i][1];
                        if (make_pair(cl, cr) < make_pair(L, R))
                            L = cl, R = cr;
                    }
                } else {
                    if (pos[i].size() && pos[j].size()) {
                        if (make_pair(pos[i][0], pos[j][0]) < make_pair(L, R))
                            L = pos[i][0], R = pos[j][0];
                    }
                }
            }
        }

        if (L == INT_MAX)
            cout << "-1 -1\n";
        else
            cout << L << " " << R << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

