//I was close but in the end had to refer to solution as well
#include <bits/stdc++.h>
using namespace std;

ifstream fin("taming.in");
ofstream fout("taming.out");

const int mxN=101;
int n, a[mxN], dp[mxN][mxN][mxN], ans[mxN];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    memset(ans, 0x3f, sizeof(ans));
    fin >> n;
    for (int i=0; i<n; ++i)
        fin >> a[i];
    dp[1][0][0]=(a[0]!=0);
    for (int i=1; i<n; ++i) {
        for (int j=0; j<=i; ++j)
            for (int k=1; k<=i+1; ++k) {
                if (i==j)
                    for (int l=0; l<i; ++l)
                        dp[k][i][j]=min(dp[k][i][j], dp[k-1][i-1][l]);
                else
                    dp[k][i][j]=dp[k][i-1][j];
                dp[k][i][j]+=(i-j!=a[i]);
            }
    }
    for (int i=1; i<=n; ++i)
        for (int j=0; j<n; ++j)
            ans[i]=min(ans[i], dp[i][n-1][j]);
    for (int i=1; i<=n; ++i)
        fout << ans[i] << '\n';
}

