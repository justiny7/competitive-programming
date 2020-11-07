#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+5;
int n, a[mxN], dp[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    memset(dp, 0x3f, sizeof(dp));
    dp[0]=0;
    for (int i=0; i<n; ++i) {
        dp[i+1]=min(dp[i+1], dp[i]+abs(a[i+1]-a[i]));
        dp[i+2]=min(dp[i+2], dp[i]+abs(a[i+2]-a[i]));
    }
    cout << dp[n-1] << '\n';
}
