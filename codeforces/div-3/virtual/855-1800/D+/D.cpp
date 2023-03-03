#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int res = 0;
    for (int i = 0; i < n - 1; ++i)
        if (s[i] == 0 || s[i - 1] != s[i + 1])
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

