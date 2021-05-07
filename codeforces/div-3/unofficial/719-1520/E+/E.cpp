#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        vector<ll> mn(n);
        ll p = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*')
                ++p;
            else
                mn[i] = p;
        }
        p = 0;
        for (int i = n - 1; ~i; --i) {
            if (s[i] == '*')
                ++p;
            else
                mn[i] = min(mn[i], p);
        }
        cout << accumulate(mn.begin(), mn.end(), 0LL) << '\n';
    }
}
