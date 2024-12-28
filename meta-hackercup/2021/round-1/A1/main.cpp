#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int c = 0;
    char lst = 'F';
    for (int i = 0; i < n; ++i) {
        if (s[i] == lst || s[i] == 'F')
            continue;

        ++c;
        lst = s[i];
    }

    cout << max(0, c - 1) << '\n';
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

