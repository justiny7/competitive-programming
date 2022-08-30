#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    for (char &c : s)
        if (c == 'G')
            c = 'B';
    for (char &c : t)
        if (c == 'G')
            c = 'B';

    cout << (s == t ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

