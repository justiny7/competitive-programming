#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    bool f = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            if (f) {
                cout << "NO\n";
                return;
            }
        } else if (a[i] > a[i - 1]) {
            if (!f)
                f = 1;
        }
    }

    cout << "YES\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

