#include <bits/stdc++.h>
using namespace std;

const int mxN=3e3+1, INF=0x3f3f3f3f;
int n, a[mxN], b[mxN], dp[3][mxN];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    for (int i=0; i<n; ++i)
        cin >> b[i], dp[0][i]=b[i];
    for (int i=1; i<3; ++i)
        for (int j=0; j<n; ++j)
            for (int k=0; k<j; ++k)
                if (a[k]<a[j] && dp[i-1][k]^INF)
                    dp[i][j]=min(dp[i][j], dp[i-1][k]+b[j]);
    int ans=INF;
    for (int i=0; i<n; ++i)
        ans=min(ans, dp[2][i]);
    cout << (ans^INF?ans:-1) << '\n';
}

