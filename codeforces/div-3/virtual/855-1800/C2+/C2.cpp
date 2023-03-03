#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    ll res = 0;
    priority_queue<int> pq;
    while (n--) {
        ll x;
        cin >> x;

        if (x)
            pq.push(x);
        else if (pq.size()) {
            res += pq.top();
            pq.pop();
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

