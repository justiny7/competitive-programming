#include <bits/stdc++.h>
using namespace std;

const int mxN=71;
int n, m, M, a[mxN][mxN], dp[mxN][mxN], dp2[mxN];

void go(int i) {
    int cur_dp[mxN][mxN][mxN];
    memset(cur_dp, -1, sizeof(cur_dp));
    cur_dp[0][0][0]=0; //iteration, mod, cnt
    for (int j=0; j<m; ++j)
        for (int k=0; k<M; ++k)
            for (int l=0; l<=m/2; ++l)
                if (~cur_dp[j][k][l]) {
                    if (l<m/2)
                        cur_dp[j+1][(k+a[i][j])%M][l+1]=max(cur_dp[j+1][(k+a[i][j])%M][l+1], cur_dp[j][k][l]+a[i][j]);
                    cur_dp[j+1][k][l]=max(cur_dp[j+1][k][l], cur_dp[j][k][l]);
                }
    for (int j=0; j<=m/2; ++j)
        for (int k=0; k<M; ++k)
            dp[i+1][k]=max(dp[i+1][k], cur_dp[m][k][j]);
}

int main() {
    memset(dp, -1, sizeof(dp));
    dp[0][0]=0;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> M;
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j)
            cin >> a[i][j];
    for (int i=0; i<n; ++i)
        go(i);
    for (int i=1; i<=n; ++i) {
        memset(dp2, -1, sizeof(dp2));
        for (int j=0; j<M; ++j)
            for (int k=0; k<M; ++k)
                if (~dp[i-1][k] && ~dp[i][j])
                    dp2[(j+k)%M]=max(dp2[(j+k)%M], dp[i-1][k]+dp[i][j]);
        for (int j=0; j<M; ++j)
            dp[i][j]=dp2[j];
    }
    cout << dp[n][0] << '\n';
}

