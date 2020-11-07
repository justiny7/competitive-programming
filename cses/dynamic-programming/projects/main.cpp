#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
ll n, ans, dp[mxN*2];
array<ll, 3> p[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> p[i][1] >> p[i][0] >> p[i][2];
    sort(p+1, p+n+1);
    for (int i=1; i<=n; ++i) {
        dp[i]=max(dp[i-1], p[i][2]);
        int j=lower_bound(p, p+n, array<ll, 3>{p[i][1], 0, 0})-p;
        if (j)
            dp[i]=max(dp[i], dp[j-1]+p[i][2]);
    }
    cout << dp[n] << '\n';
}

