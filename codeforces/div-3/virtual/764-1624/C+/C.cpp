#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    multiset<int> have;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        while (x > n)
            x /= 2;

        have.insert(x);
    }

    for (int i = n; i; --i) {
        if (have.count(i) == 0) {
            cout << "NO\n";
            return;
        }

        while (have.count(i) > 1) {
            have.erase(have.find(i));
            have.insert(i / 2);
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

