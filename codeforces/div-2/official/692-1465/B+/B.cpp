#include <bits/stdc++.h>
using namespace std;
using ll=long long;

inline bool ok(ll x) {
    ll cp=x;
    while (cp) {
        ll M=cp%10;
        if (M && x%M)
            return 0;
        cp/=10;
    }
    return 1;
}

void solve() {
    ll x; cin >> x;
    while (!ok(x))
        ++x;
    cout << x << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}

