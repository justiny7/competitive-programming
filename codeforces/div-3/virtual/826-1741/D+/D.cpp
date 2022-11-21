#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    int res = 0;
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 0; j < n; j += (1 << i)) {
            int k = 1 << (i - 1);
            if (a[j] == a[j + k] + k) {
                ++res;
                swap(a[j], a[j + k]);
            } else if (a[j] + k != a[j + k]) {
                cout << "-1\n";
                return;
            }
        }

        // for (int j : a)
            // cout << j << " ";
        // cout << '\n';
    }
    
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

