#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    map<int, int> mp;
    while (n--) {
        int x;
        cin >> x;
        ++mp[x];
    }

    if (mp.size() > k * 2)
        cout << "NO\n";
    else {
        for (auto [x, c] : mp) {
            if (c > 2) {
                cout << "NO\n";
                return;
            }
        }

        cout << "YES\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

