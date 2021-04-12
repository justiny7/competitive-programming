#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; string s;
    cin >> n >> k >> s;
    if (k == 0)
        cout << "YES\n";
    else if (k * 2 >= n)
        cout << "NO\n";
    else {
        bool f = 1;
        for (int i = 0; i < k; ++i)
            f &= (s[i] == s[n - i - 1]);
        cout << (f ? "YES" : "NO") << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
