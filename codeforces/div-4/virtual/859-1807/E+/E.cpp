#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<int> pref(n + 1);
    for (int i = 1; i <= n; ++i)
        pref[i] = pref[i - 1] + a[i - 1];

    int lo = 1, hi = n;
    while (lo < hi) {
        int m = lo + hi >> 1;

        cout << "? " << m;
        for (int i = 1; i <= m; ++i)
            cout << " " << i;
        cout << endl;

        int sum;
        cin >> sum;

        if (sum == pref[m])
            lo = m + 1;
        else
            hi = m;

        // cout << "> " << lo << " " << hi << '\n';
    }

    cout << "! " << lo << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}

