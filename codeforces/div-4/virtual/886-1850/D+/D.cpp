#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    sort(a.begin(), a.end());

    int mx = 1, cur = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > k) {
            mx = max(mx, cur);
            cur = 1;
        } else {
            ++cur;
            mx = max(mx, cur);
        }
    }

    cout << n - mx << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

