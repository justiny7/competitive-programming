#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    sort(a.rbegin(), a.rend());

    for (int i = 1; i < n; ++i)
        a[i] += a[i - 1];

    while (q--) {
        int x;
        cin >> x;

        auto it = lower_bound(a.begin(), a.end(), x);

        if (it == a.end())
            cout << "-1\n";
        else
            cout << (it - a.begin()) + 1 << '\n';
    }

}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}


