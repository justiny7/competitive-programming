#include <bits/stdc++.h>
using namespace std;
using ll=long long;
//Had to look at solution T-T
ifstream fin("cbarn2.in");
ofstream fout("cbarn2.out");

const int mxN=101;
ll n, k, a[mxN], dp[mxN][8], ans=INT_MAX;

int main() {
    fin >> n >> k;
    for (int i=0; i<n; ++i)
        fin >> a[i];
    for (int st=0; st<n; ++st) {
        memset(dp, 0x3f, sizeof(dp));
        dp[n][0]=0;
        for (int j=1; j<=k; ++j)
            for (int i=0; i<n; ++i) {
                ll cur=0;
                for (int l=i+1; l<=n; ++l) {
                    cur+=a[l-1]*(l-i-1);
                    dp[i][j]=min(dp[i][j], cur+dp[l][j-1]);
                }
            }
        rotate(a, a+1, a+n);
        ans=min(ans, dp[0][k]);
    }
    fout << ans << '\n';
}
