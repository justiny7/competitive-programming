#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    int res = 0;
    for (int i = 1; i < n; ++i)
        res = gcd(res, abs(a[i] - a[i - 1]));

    cout << (res ? res : -1) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

