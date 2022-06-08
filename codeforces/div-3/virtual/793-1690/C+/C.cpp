#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> s(n), f(n);
    for (int &i : s)
        cin >> i;
    for (int &i : f)
        cin >> i;

    int t = 0;
    for (int i = 0; i < n; ++i) {
        t = max(s[i], t);
        cout << f[i] - t << " ";
        t = f[i];
    }

    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

