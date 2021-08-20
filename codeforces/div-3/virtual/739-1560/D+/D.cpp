#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int calc(ll a, ll b) {
    string s = to_string(a), t = to_string(b);

    int same = 0, del = 0;
    for (int i = 0, j = 0; i < s.size(); ++i) {
        if (j < t.size() && s[i] == t[j]) {
            ++same;
            ++j;
        } else {
            ++del;
        }
    }

    return del + (t.size() - same);
}
void solve() {
    ll n;
    cin >> n;

    int ans = INT_MAX;
    for (int i = 0; i < 64; ++i) {
        ll targ = 1LL << i;
        ans = min(ans, calc(n, targ));
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

