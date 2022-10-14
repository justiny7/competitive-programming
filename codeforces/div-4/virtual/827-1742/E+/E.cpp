#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    vector<ll> pref(n + 1), mx(a);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
        if (i)
            mx[i] = max(mx[i], mx[i - 1]);
    }

    while (q--) {
        int k;
        cin >> k;

        int ind = (upper_bound(mx.begin(), mx.end(), k) - mx.begin());
        cout << pref[ind] << " ";
    }
    
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}

