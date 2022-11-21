#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<char> ok(n + 1);
    ok[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (a[i] + i <= n)
            ok[i + a[i] + 1] |= ok[i];
        if (i - a[i] >= 0)
            ok[i + 1] |= ok[i - a[i]];
    }

    cout << (ok[n] ? "YES" : "NO") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

