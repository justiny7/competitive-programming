#include <bits/stdc++.h>
using namespace std;

int f(char c) {
    return (c - 'a');
}
int f2(char a, char b) {
    return f(a) * 26 + f(b);
}
int f3(char a, char b, char c) {
    return f(a) * 26 * 26 + f2(b, c);
}

void solve() {
    int n, m;
    cin >> n >> m;

    map<int, array<int, 3>> two, three;
    for (int t = 1; t <= n; ++t) {
        string s;
        cin >> s;

        for (int i = 0; i < m; ++i) {
            if (i + 1 < m)
                two[f2(s[i], s[i + 1])] = {i + 1, i + 2, t};
            if (i + 2 < m)
                three[f3(s[i], s[i + 1], s[i + 2])] = {i + 1, i + 3, t};
        }
    }

    string targ;
    cin >> targ;

    vector<int> dp(m + 1, -1);
    vector<array<int, 3>> prv(m + 1, {-1, -1, -1});
    dp[0] = 0;
    prv[0] = {0, 0, 0};
    for (int i = 0; i < m; ++i) {
        if (dp[i] < 0)
            continue;

        if (i + 1 < m && two.count(f2(targ[i], targ[i + 1]))) {
            dp[i + 2] = i;
            prv[i + 2] = two[f2(targ[i], targ[i + 1])];
        }
        if (i + 2 < m && three.count(f3(targ[i], targ[i + 1], targ[i + 2]))) {
            dp[i + 3] = i;
            prv[i + 3] = three[f3(targ[i], targ[i + 1], targ[i + 2])];
        }
    }

    if (dp[m] < 0) {
        cout << "-1\n";
        return;
    }

    int cur = m;
    vector<array<int, 3>> res;
    while (cur > 0) {
        res.push_back(prv[cur]);
        cur = dp[cur];
    }

    cout << res.size() << '\n';
    for (int i = res.size() - 1; ~i; --i)
        cout << res[i][0] << " " << res[i][1] << " " << res[i][2] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

