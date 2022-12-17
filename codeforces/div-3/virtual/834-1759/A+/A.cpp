#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != 'Y' && s[i] != 'e' && s[i] != 's') {
            cout << "NO\n";
            return;
        }

        if (i == 0)
            continue;

        if (s[i] == 'Y' && s[i - 1] != 's') {
            cout << "NO\n";
            return;
        } else if (s[i] == 'e' && s[i - 1] != 'Y') {
            cout << "NO\n";
            return;
        } else if (s[i] == 's' && s[i - 1] != 'e') {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

