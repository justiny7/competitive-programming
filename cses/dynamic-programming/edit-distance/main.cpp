#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];
string a, b;

int main(void) {
    cin >> a >> b;
    for (int i=1; i<=a.length(); ++i)
        dp[i][0]=i;
    for (int i=1; i<=b.length(); ++i)
        dp[0][i]=i;
    for (int i=1; i<=a.length(); ++i)
        for (int j=1; j<=b.length(); ++j) {
            dp[i][j]=INT_MAX;
            if (a[i-1]==b[j-1])
                dp[i][j]=dp[i-1][j-1];
            dp[i][j]=min(min(dp[i][j]-1, dp[i-1][j-1]), min(dp[i-1][j], dp[i][j-1]))+1;
        }
    cout << dp[a.length()][b.length()] << '\n';
}
