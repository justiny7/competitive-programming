#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+5;
int n, k, a[mxN], dp[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;
    for (int i=0; i<n; ++i)
        for (int j=1; j<=k; ++j)
            dp[i+j]=min(dp[i+j], dp[i]+abs(a[i]-a[i+j]));
    cout << dp[n-1] << '\n';
}

