#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+5;
int n, m, a[mxN][mxN], dp[mxN][mxN][4];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            cin >> a[i][j];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j)
            dp[i][j][0]=a[i][j]+max(dp[i-1][j][0], dp[i][j-1][0]);
    for (int i=1; i<=n; ++i)
        for (int j=m; j; --j)
            dp[i][j][1]=a[i][j]+max(dp[i-1][j][1], dp[i][j+1][1]);
    for (int i=n; i; --i)
        for (int j=1; j<=m; ++j)
            dp[i][j][2]=a[i][j]+max(dp[i+1][j][2], dp[i][j-1][2]);
    for (int i=n; i; --i)
        for (int j=m; j; --j)
            dp[i][j][3]=a[i][j]+max(dp[i+1][j][3], dp[i][j+1][3]);
    int ans=0;
    for (int i=2; i<n; ++i)
        for (int j=2; j<m; ++j) {
            ans=max(ans, dp[i][j-1][0]+dp[i][j+1][3]+dp[i+1][j][2]+dp[i-1][j][1]);
            ans=max(ans, dp[i-1][j][0]+dp[i+1][j][3]+dp[i][j-1][2]+dp[i][j+1][1]);
        }
    cout << ans << '\n';
}

