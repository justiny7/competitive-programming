#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    int res = 0;
    map<int, int> pref;
    
    int p = 0;
    for (int i = 0; i < n; ++i) {
        p += a[i];
        pref[p] = i;
    }

    p = 0;
    for (int i = n - 1; ~i; --i) {
        p += a[i];

        if (!pref.count(p) || pref[p] >= i)
            continue;
        res = max(res, pref[p] + 1 + n - i);
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

