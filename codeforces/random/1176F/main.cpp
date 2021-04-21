#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int K = 10, C = 3;
int n; ll dp[K], ndp[K];

void op(vector<ll> a) {
    int c = a.size();
    ll s = accumulate(a.begin(), a.end(), 0LL),
       mx = *max_element(a.begin(), a.end());
    for (int i = 0; i < K; ++i) {
        if (dp[i] < 0)
            continue;
        int to = (i + c) % K;
        ndp[to] = max(ndp[to], dp[i] + s + (i < K - c ? 0 : mx));
    }
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp[0] = 0;
    while (n--) {
        for (int i = 0; i < K; ++i)
            ndp[i] = dp[i];
        int k; cin >> k;
        vector<ll> a[C];
        while (k--) {
            int t; ll x;
            cin >> t >> x;
            a[t - 1].push_back(x);
        }
        for (int i = 0; i < C; ++i)
            sort(a[i].rbegin(), a[i].rend());
        if (a[0].size())
            op({a[0][0]});
        if (a[0].size() >= 2)
            op({a[0][0], a[0][1]});
        if (a[0].size() >= 3)
            op({a[0][0], a[0][1], a[0][2]});
        if (a[1].size())
            op({a[1][0]});
        if (a[0].size() && a[1].size())
            op({a[0][0], a[1][0]});
        if (a[2].size())
            op({a[2][0]});
        for (int i = 0; i < K; ++i)
            dp[i] = ndp[i];
    }
    ll ans = 0;
    for (int i = 0; i < K; ++i)
        ans = max(ans, dp[i]);
    cout << ans << '\n';
}
