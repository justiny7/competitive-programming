#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
int n, dp[1000001];

int main(void) {
    cin >> n;
    dp[0]=1;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=6; ++j)
            if (i-j>=0)
                dp[i]=(dp[i]+dp[i-j])%MOD;
    cout << dp[n] << '\n';
}
