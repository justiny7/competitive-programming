#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<char>> ans(n, vector<char>(n, '='));
    for (int i = 0; i < n; ++i)
        ans[i][i] = 'X';

    vector<int> win;
    for (int i = 0; i < n; ++i)
        if (s[i] == '2')
            win.push_back(i);

    if (win.size() == 1 || win.size() == 2) {
        cout << "NO\n";
        return;
    }

    int sz = win.size();
    for (int i = 0; i < sz; ++i) {
        int j = (i + 1) % sz;
        ans[win[i]][win[j]] = '+';
        ans[win[j]][win[i]] = '-';
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << ans[i][j];
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

