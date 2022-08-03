#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    int need = -1;
    for (int i : a) {
        if (i % 10 == 0)
            need = i;
        else if (i % 5 == 0)
            need = i + 5;
    }

    if (~need) {
        for (int i : a) {
            if (i != need && i != need - 5) {
                cout << "No\n";
                return;
            }
        }
        cout << "Yes\n";
        return;
    }

    for (int &i : a)
        while (i % 10 != 2)
            i = i + (i % 10);

    for (int i = 1; i < n; ++i) {
        if (abs(a[i] - a[i - 1]) % 20) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

