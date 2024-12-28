#include <bits/stdc++.h>
using namespace std;

using ll = long long;

set<ll> pos;

void solve() {
    ll A, B, M;
    cin >> A >> B >> M;

    auto it = pos.lower_bound(A);
    int res = 0;
    while (it != pos.end() && *it <= B) {
        res += (*it % M == 0);
        it++;
    }

    cout << res << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int len = 1; len <= 17; len += 2) {
        for (int st = 1; st <= 9; st++) {
            ll cur = 0, add = st;
            for (int i = 0; i <= len / 2; i++) {
                cur = cur * 10 + (add++);
            }

            if (add > 10) {
                continue;
            }

            add--;
            for (int i = 0; i < len / 2; i++) {
                cur = cur * 10 + (--add);
            }

            pos.insert(cur);
        }
    }

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++) {
        cout << "Case #" << tt << ": ";
        solve();
    }
}
