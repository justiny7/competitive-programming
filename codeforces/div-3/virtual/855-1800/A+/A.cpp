#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    for (char &c : s)
        c = tolower(c);

    string res;
    res += s[0];
    for (int i = 1; i < n; ++i)
        if (s[i] != res.back())
            res += s[i];

    cout << (res == "meow" ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

