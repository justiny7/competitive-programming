#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    set<char> have;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            if (have.size() == 1) {
                cout << "NO\n";
                return;
            }
            have.clear();
        } else {
            have.insert(s[i]);
        }
    }

    if (have.size() == 1)
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

