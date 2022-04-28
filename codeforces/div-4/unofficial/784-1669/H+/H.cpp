#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    
    vector<int> need(31);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 31; ++j)
            if (!(a[i] & (1 << j)))
                ++need[j];
    }

    int res = 0;
    for (int i = 30; ~i; --i) {
        if (need[i] <= k) {
            k -= need[i];
            res |= (1 << i);
        }
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

