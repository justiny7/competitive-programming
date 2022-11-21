#include <bits/stdc++.h>
using namespace std;

void solve() {
    vector<int> a(3);
    cin >> a[0] >> a[1] >> a[2];

    sort(a.begin(), a.end());
    cout << a[1] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

