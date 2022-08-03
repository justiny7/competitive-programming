#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    set<int> s;
    for (int i = n - 1; ~i; --i) {
        if (s.count(a[i])) {
            cout << i + 1 << '\n';
            return;
        }

        s.insert(a[i]);
    }

    cout << 0 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

