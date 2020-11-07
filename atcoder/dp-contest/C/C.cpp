#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, dp[mxN][3], a, b, c;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0]=dp[0][1]=dp[0][2]=0;
    for (int i=1; i<=n; ++i) {
        cin >> a >> b >> c;
        dp[i][0]=max(dp[i-1][1]+b, dp[i-1][2]+c);
        dp[i][1]=max(dp[i-1][0]+a, dp[i-1][2]+c);
        dp[i][2]=max(dp[i-1][1]+b, dp[i-1][0]+a);
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
}
