#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=201;
ll n, k, x, a[mxN], dp[mxN][mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> x;
    for (int i=1; i<=n; ++i)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    for (int i=1; i<=k; ++i)
        dp[1][i]=a[i];
    for (int i=2; i<=x; ++i)
        for (int j=1; j<=n; ++j)
            for (int l=max(1LL, j-k); l<j; ++l)
                if (~dp[i-1][l])
                    dp[i][j]=max(dp[i][j], dp[i-1][l]+a[j]);
    ll ans=-1;
    for (int i=n-k+1; i<=n; ++i)
        ans=max(ans, dp[x][i]);
    cout << ans << '\n';
}

