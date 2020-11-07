#include <bits/stdc++.h>
using namespace std;

int n, x, c[101], dp[1000001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i=0; i<n; ++i)
        cin >> c[i];
    fill(dp, dp+x+1, INT_MAX);
    dp[0]=0;
    for (int i=1; i<=x; ++i)
        for (int j=0; j<n; ++j)
            if (i-c[j]>=0 && dp[i-c[j]]!=INT_MAX)
                dp[i]=min(dp[i], dp[i-c[j]]+1);
    if (dp[x]==INT_MAX)
        cout << "-1\n";
    else
        cout << dp[x] << '\n';
}
