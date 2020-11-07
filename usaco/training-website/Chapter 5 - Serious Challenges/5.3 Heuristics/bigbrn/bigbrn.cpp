/*
ID: justiny7
LANG: C++
TASK: bigbrn
*/

//A very easy dp that worked first try
#include <bits/stdc++.h>
using namespace std;

ifstream fin("bigbrn.in");
ofstream fout("bigbrn.out");

const int mxN=1e3+1;
int n, t, dp[mxN][mxN], ans;

int main(void) {
    memset(dp, -1, sizeof(dp));
    fin >> n >> t;
    for (int i=0; i<t; ++i) {
        int a, b;
        fin >> a >> b;
        dp[a][b]=0;
    }
    for (int i=0; i<=n; ++i)
        dp[i][0]=dp[0][i]=0;
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            if (dp[i][j])
                dp[i][j]=min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1, ans=max(ans, dp[i][j]);
    fout << ans << '\n';
}
