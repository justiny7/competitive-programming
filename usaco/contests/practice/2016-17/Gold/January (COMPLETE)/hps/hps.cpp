#include <bits/stdc++.h>
using namespace std;
//A kinda confusing dp problem that took too long to debug
ifstream fin("hps.in");
ofstream fout("hps.out");

const int mxN=1e5+1;
int n, k, dp[mxN][21][3], a[mxN], m[256];

int main() {
    fin >> n >> k;
    m['H']=0, m['P']=1, m['S']=2;
    for (int i=0; i<n; ++i) {
        char c; fin >> c;
        a[i]=m[c];
    }
    for (int i=0; i<n; ++i) {
        for (int j=0; j<3; ++j) {
            int win=(j==((a[i]+1)%3));
            if (!i) {
                dp[0][0][j]=win;
                continue;
            }
            for (int l=0; l<=min(i, k); ++l)
                for (int t=0; t<3; ++t) {
                    if (t!=j && l)
                        dp[i][l][j]=max(dp[i][l][j], win+dp[i-1][l-1][t]);
                    else if (t==j)
                        dp[i][l][j]=max(dp[i][l][j], win+dp[i-1][l][t]);
                }
        }
    }
    int ans=0;
    for (int j=0; j<3; ++j)
        ans=max(ans, dp[n-1][k][j]);
    fout << ans << '\n';
}
