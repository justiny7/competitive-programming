#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<int> a(n), b;
    for (int &i : a)
        cin >> i;

    if (is_sorted(a.begin(), a.end()))
        cout << "YES\n";
    else {
        vector<int> b(a);
        sort(b.begin(), b.end());

        bool f = 1;
        for (int i = x - 1; i + x >= n; --i)
            f &= a[i] == b[i];

        cout << (f ? "YES" : "NO") << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

