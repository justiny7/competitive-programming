#include <bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
int n, x, c[101], dp[1000001];

int main(void) {
    cin >> n >> x;
    for (int i=0; i<n; ++i)
        cin >> c[i];
    dp[0]=1;
    for (int i=1; i<=x; ++i)
        for (int j=0; j<n; ++j)
            if (i-c[j]>=0)
                dp[i]=(dp[i]+dp[i-c[j]])%MOD;
    cout << dp[x] << '\n';
}
