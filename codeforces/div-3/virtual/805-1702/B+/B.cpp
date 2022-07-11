#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int res = 0;
    set<char> cur;
    for (int i = 0; i < s.size(); ++i) {
        if (cur.count(s[i]))
            continue;

        cur.insert(s[i]);
        if (cur.size() == 4) {
            ++res;
            cur.clear();
            cur.insert(s[i]);
        }
    }

    if (cur.size())
        ++res;

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

