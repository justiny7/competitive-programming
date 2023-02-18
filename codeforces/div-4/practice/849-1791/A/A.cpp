#include <bits/stdc++.h>
using namespace std;

void solve() {
    set<char> s;
    for (char c : "codeforces")
        s.insert(c);

    char a;
    cin >> a;

    cout << (s.count(a) ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

