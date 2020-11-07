#include <bits/stdc++.h>
using namespace std;

const int mxN=500, mxK=9, mxC=16;
int n, m, dp[mxN][mxN][mxK][mxC];
string s[mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> s[i];
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m-1; ++j) {
            int msk=(s[i][j]=='*')+((s[i+1][j]=='*')<<1)+
                    ((s[i][j+1]=='*')<<2)+((s[i+1][j+1]=='*')<<3);
            dp[i][j][1][msk]=1;
        }
    int ans=0;
    for (int k=2; k<mxK; ++k)
        for (int i=0; i<=n-(1<<k); ++i)
            for (int j=0; j<=m-(1<<k); ++j)
                for (int msk=0; msk<mxC; ++msk) {
                    int f=1;
                    f&=(dp[i][j][k-1][((msk&1)?15:msk)]);
                    f&=(dp[i+(1<<(k-1))][j][k-1][((msk&(1<<1))?15:msk)]);
                    f&=(dp[i][j+(1<<(k-1))][k-1][((msk&(1<<2))?15:msk)]);
                    f&=(dp[i+(1<<(k-1))][j+(1<<(k-1))][k-1][((msk&(1<<3))?15:msk)]);
                    ans+=(dp[i][j][k][msk]=f);
                }
    cout << ans << '\n';
}

