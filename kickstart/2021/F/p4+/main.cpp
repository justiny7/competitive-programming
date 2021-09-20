#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> l(n), r(n), a(n);
    for (int i = 0; i < n; ++i)
        cin >> l[i] >> r[i] >> a[i];

    vector<vector<int>> adj(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // dp[msk] = # of ways
    vector<ll> dp(1 << n);
    for (int i = 0; i < n; ++i)
        dp[1 << i] = 1;
    for (int i = 1; i < (1 << n); ++i) {
        vector<int> here;
        int sum = 0;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                here.push_back(j), sum += a[j];

        set<int> can;
        for (int v : here)
            for (int u : adj[v])
                can.insert(u);

        for (int u : can)
            if (!(i & (1 << u)) && sum >= l[u] && sum <= r[u])
                dp[i | (1 << u)] += dp[i];
    }

    ll ans = 0;
    for (int i = 1; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j)
            if (i & (1 << j))
                sum += a[j];

        if (sum == k)
            ans += dp[i];

        // cout << "state: " << bitset<4>(i) << " " << sum << '\n';
        // cout << dp[i] << '\n';
    }

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

