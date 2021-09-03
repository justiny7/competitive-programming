#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    if (a.back() == 0) {
        for (int i = 1; i <= n + 1; ++i)
            cout << i << " \n"[i == n + 1];
        return;
    }

    for (int i = 1; i < n; ++i) {
        if (a[i - 1] == 0 && a[i] == 1) {
            for (int j = 1; j <= i; ++j)
                cout << j << " ";
            cout << n + 1;
            for (int j = i + 1; j <= n; ++j)
                cout << " " << j;
            cout << '\n';
            return;
        }
    }

    cout << n + 1;
    for (int i = 1; i <= n; ++i)
        cout << " " << i;
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

