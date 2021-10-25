#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class t> using oset = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    oset<array<int, 2>> o;
    map<int, int> mp;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        ll q = o.order_of_key({x, -1});
        ans += min(q, (ll)i - q - mp[x]);

        ++mp[x];
        o.insert({x, i});
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

