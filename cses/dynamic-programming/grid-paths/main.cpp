#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
int n, dp[1001][1001];
string b[1001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> b[i];
    if (b[0][0]=='.')
        dp[1][1]=1;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (b[i-1][j-1]=='.') {
                dp[i][j]+=(dp[i-1][j]+dp[i][j-1]);
                dp[i][j]%=MOD;
            }
    cout << dp[n][n] << '\n';
}
