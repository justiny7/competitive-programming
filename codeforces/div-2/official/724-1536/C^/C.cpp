#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    map<pair<int, int>, int> mp;
    int d = 0, k = 0;
    for (int i = 0; i < n; ++i) {
        d += (s[i] == 'D'), k += (s[i] == 'K');
        int g = gcd(d, k), dd = d / g, dk = k / g;
        cout << ++mp[make_pair(dd, dk)] << " \n"[i == n - 1];
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
        solve();
}
