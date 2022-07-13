#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    set<char> seen;

    int res = 0;
    for (char c : s) {
        if (seen.count(c))
            ++res;
        else {
            seen.insert(c);
            res += 2;
        }
    }

    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}


