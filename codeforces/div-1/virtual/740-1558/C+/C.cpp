#include <bits/stdc++.h>
using namespace std;

void go(int x, vector<int> &ops, vector<int> &a) {
    ops.push_back(x);
    reverse(a.begin(), a.begin() + x);
    
    // for (int i : a)
        // cout << i << " ";
    // cout << '\n';
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == i % 2) {
            cout << "-1\n";
            return;
        }
    }

    vector<int> ops;
    for (int i = n; i > 1; i -= 2) {
        int d1 = find(a.begin(), a.end(), i) - a.begin() + 1;
        go(d1, ops, a);
        int d2 = find(a.begin(), a.end(), i - 1) - a.begin() + 1;
        go(d2 - 1, ops, a);
        go(d2 + 1, ops, a);
        go(3, ops, a);
        go(i, ops, a);
    }

    cout << ops.size() << '\n';
    for (int i : ops)
        cout << i << " ";
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

