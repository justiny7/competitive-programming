#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll Q = 1e18 + 1;
set<ll> ok;
bool check(ll p, ll i) {
    return (log(p) + log(i) <= log(1e18));
}
void go() {
    for (int i = 2; i <= 1e6; ++i) {
        ll p = 1LL * i * i, s = 1 + i + p;
        while (check(p, i) && s < Q) {
            p *= i;
            s += p;
            
            // cout << p << " " << s << '\n';
            if (s < Q)
                ok.insert(s);
        }
        // cout << i << " " << ok.size() << '\n';
    }
    // cout << "DONE\n";
}

void solve() {
    ll n;
    cin >> n;

    if (ok.count(n))
        cout << "YES\n";
    else {
        ll lo = 2, hi = 1e9;
        while (lo < hi) {
            ll m = lo + hi >> 1;

            if (m * m + m + 1 >= n)
                hi = m;
            else
                lo = m + 1;
        }

        // cout << "! " << lo << '\n';
        if (lo * lo + lo + 1 == n)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    go();

    int t;
    cin >> t;
    while (t--)
        solve();
}

