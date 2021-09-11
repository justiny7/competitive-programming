#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    string s;
    cin >> s;

    ll a = 0, b = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (i & 1)
            a = a * 10 + (s[i] - '0');
        else
            b = b * 10 + (s[i] - '0');
    }

    cout << (a + 1) * (b + 1) - 2 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

