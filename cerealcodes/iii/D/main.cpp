#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

// dp[position][s1 last char][s2 last char] = min number of 01 pairs
int dp[N][2][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n;
    string s, t;
    cin >> n >> s >> t;

    auto get = [&](char x, char y) {
        x = x - 'a', y = y - 'a';
        if (x == y) {
            return 0;
        }
        if ((x + y == 25)) {
            return 1;
        }
        if ((x + 13) % 26 == y) {
            return 2;
        }
        if (x + ((y + 13) % 26) == 25) {
            return 3;
        }
        return -1;
    };

    vector<int> s1(n + 1), s2(n + 1);
    for (int i = 0; i < n; i++) {
        int q = get(s[i], t[i]);
        if (q == -1) {
            cout << "-1\n";
            return 0;
        }

        if (s[i] != 'g' && s[i] != 't') {
            s1[i + 1] = bool(q & 1);
            s2[i + 1] = bool(q & 2);
        } else if (s[i] == t[i]) {
            s1[i + 1] = s2[i + 1] = -2;
        } else {
            s1[i + 1] = s2[i + 1] = -1;
        }
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        vector<array<int, 2>> here, prev;
        if (s1[i] == -1) {
            here.push_back({0, 1});
            here.push_back({1, 0});
        } else if (s1[i] == -2) {
            here.push_back({0, 0});
            here.push_back({1, 1});
        } else {
            here.push_back({s1[i], s2[i]});
        }

        if (s1[i - 1] == -1) {
            prev.push_back({0, 1});
            prev.push_back({1, 0});
        } else if (s1[i - 1] == -2) {
            prev.push_back({0, 0});
            prev.push_back({1, 1});
        } else {
            prev.push_back({s1[i - 1], s2[i - 1]});
        }

        for (auto [h1, h2] : here) {
            for (auto [p1, p2] : prev) {
                dp[i][h1][h2] = min(dp[i][h1][h2], dp[i - 1][p1][p2] +
                    (p1 == 0 && h1 == 1) +
                    (p2 == 0 && h2 == 1));
            }
        }
    }

    int res = INT_MAX;
    for (int i : {0, 1}) {
        for (int j : {0, 1}) {
            res = min(res, dp[n][i][j]);
        }
    }

    cout << res << '\n';
}

