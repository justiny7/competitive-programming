#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;

    int p = 0;
    for (char &c : s) {
        if (p < t.size() && (c == '?' || c == t[p])) {
            c = t[p];
            p++;
        }
    }

    for (char &c : s) {
        if (c == '?') {
            c = 'a';
        }
    }

    if (p == t.size()) {
        cout << "YES\n" << s << '\n';
    } else {
        cout << "NO\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}

