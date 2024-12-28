#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    if (s[0] == 's') {
        s[0] = '.';
    }
    if (s.back() == 'p') {
        s.back() = '.';
    }

    bool f1 = 0, f2 = 0;
    for (char c : s) {
        f1 |= (c == 's');
        f2 |= (c == 'p');
    }

    cout << ((f1 && f2) ? "NO" : "YES") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
