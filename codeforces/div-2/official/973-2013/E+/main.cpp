#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    
    set<int> s;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        s.insert(x);
    }

    ll cur = *s.begin();
    ll res = cur;
    s.erase(s.begin());
    int c = 1;
    while (true) {
        int q = 0;
        for (int x : s) {
            if (gcd(cur, x) < gcd(cur, q)) {
                q = x;
            }
        }

        if (q == 0) {
            break;
        }

        cur = gcd(cur, q);
        res += cur;
        c++;
        s.erase(q);
    }

    res += cur * (n - c);
    cout << res << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
