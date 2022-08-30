#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<ll> vals;
    ll cur = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            cur += i;
            vals.push_back((n - i - 1) - i);
        } else {
            cur += n - i - 1;
            vals.push_back(i - (n - i - 1));
        }
    }

    sort(vals.rbegin(), vals.rend());
    for (int i = 0; i < n; ++i) {
        cur += max(vals[i], 0LL);
        cout << cur << " \n"[i == n - 1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

