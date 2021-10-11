#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (ll &i : a)
        cin >> i;

    ll tot = accumulate(a.begin(), a.end(), 0LL);
    if ((tot * 2) % n) {
        cout << "0\n";
        return;
    }

    ll need = (tot * 2) / n; 
    // cout << "> " << need << '\n';

    map<ll, ll> cnt;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += cnt[need - a[i]];
        ++cnt[a[i]];
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int t;
    cin >> t;
    while (t--)
        solve();
}

