#include <bits/stdc++.h>
using namespace std;

const int mxN=3e3;
int n;
double ph[mxN], pt[mxN], dp[mxN][mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1; i<=n; ++i)
        cin >> ph[i], pt[i]=1-ph[i];
    dp[0][0]=1;
    for (int i=1; i<=n; ++i)
        for (int j=0; j<=i; ++j) {
            dp[i][j]+=dp[i-1][j]*pt[i];
            if (j)
                dp[i][j]+=dp[i-1][j-1]*ph[i];
        }
    double ans=0;
    for (int i=n/2+1; i<=n; ++i)
        ans+=dp[n][i];
    cout << setprecision(12) << ans << '\n';
}
