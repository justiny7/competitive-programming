#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1, MOD=1e9+7;
int n, m, a[mxN];
ll dp[mxN][102];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    if (a[0]>0)
        dp[0][a[0]]=1;
    else
        for (int i=1; i<=m; ++i)
            dp[0][i]=1;
    for (int i=1; i<n; ++i) {
        if (a[i]>0)
            dp[i][a[i]]=(dp[i-1][a[i]-1]+dp[i-1][a[i]]+dp[i-1][a[i]+1])%MOD;
        else
            for (int j=1; j<=m; ++j)
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%MOD;
    }
    ll ans=0;
    for (int i=1; i<=m; ++i)
        ans=(ans+dp[n-1][i])%MOD;
    cout << ans << '\n';
}
