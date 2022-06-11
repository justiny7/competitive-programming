#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

