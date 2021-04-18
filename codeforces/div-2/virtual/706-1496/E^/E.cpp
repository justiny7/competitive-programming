#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (string &i : s)
        cin >> i;
    for (int i = 0; i < n; i += 3) {
        s[i] = string(m, 'X');
        if (i + 2 >= n)
            continue;
        bool f = 0;
        for (int j = 0; j < m; ++j) {
            if (s[i + 1][j] == 'X') {
                s[i + 2][j] = 'X';
                f = 1;
                break;
            }
            if (s[i + 2][j] == 'X') {
                s[i + 1][j] = 'X';
                f = 1;
                break;
            }
        }
        if (!f)
            s[i + 1][0] = s[i + 2][0] = 'X';
    }
    if (n % 3 == 0) {
        int l = n - 1;
        bool f = 0;
        for (int i = m - 1; ~i; --i) {
            if (f)
                s[l][i] = 'X';
            if (f && s[l - 1][i] == 'X')
                f = 0;
            else if (!f && s[l][i] == 'X')
                f = 1;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << s[i] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
