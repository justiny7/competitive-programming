#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s1, s2;
    cin >> s1 >> s2;

    bool f = 0;
    for (int i = 0; i < n; ++i)
        f |= (s1[i] == '1' && s2[i] == '1');

    cout << (f ? "NO" : "YES") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

