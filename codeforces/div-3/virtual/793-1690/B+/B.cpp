#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int &i : a)
        cin >> i;
    for (int &i : b)
        cin >> i;

    int ch = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            cout << "NO\n";
            return;
        }

        if (b[i] != 0)
            ch = a[i] - b[i];
    }

    if (ch < 0) {
        cout << "YES\n";
    } else {
        for (int i = 0; i < n; ++i)
            a[i] = max(a[i] - ch, 0);
        

        cout << (a == b ? "YES" : "NO") << '\n';
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

