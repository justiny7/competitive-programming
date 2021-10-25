#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    map<char, int> mp;
    for (char c : s)
        ++mp[c];

    cout << ((mp['A'] + mp['C'] == mp['B']) ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

