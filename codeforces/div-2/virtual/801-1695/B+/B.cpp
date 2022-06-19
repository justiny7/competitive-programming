#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    if (n & 1) {
        cout << "Mike\n";
        return;
    }

    int mn = INT_MAX, ind = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] < mn) {
            ind = i;
            mn = a[i];
        }
    }

    cout << ((ind & 1) ? "Mike" : "Joe") << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

