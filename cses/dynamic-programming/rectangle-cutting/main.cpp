#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=501;
int n, m;
ll dp[mxN][mxN];

int main(void) {
    memset(dp, 0x3f, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=1; i<mxN; ++i)
        for (int j=1; j<mxN; ++j) {
            if (j==i)
                dp[i][j]=0;
            for (int k=1; k<j; ++k) //vertical cut
                dp[i][j]=min(dp[i][j], 1+dp[i][k]+dp[i][j-k]);
            for (int k=1; k<i; ++k) //horizontal cut
                dp[i][j]=min(dp[i][j], 1+dp[k][j]+dp[i-k][j]);
        }
    cout << dp[n][m] << '\n';
}

