#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    int mn = INT_MAX, ind = -1;
    for (int i = 1; i < n; ++i) {
        if (mn > a[i] - a[i - 1]) {
            mn = a[i] - a[i - 1];
            ind = i;
        }
    }

    cout << a[ind - 1];
    for (int i = ind + 1; i < n; ++i)
        cout << " " << a[i];
    for (int i = 0; i < ind - 1; ++i)
        cout << " " << a[i];
    cout << " " << a[ind] << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; cin >> t;
    while (t--)
        solve();
}
