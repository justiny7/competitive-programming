#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    char c;
    cin >> s >> c;

    for (int i = 0; i < s.size(); i += 2) {
        if (s[i] == c) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

