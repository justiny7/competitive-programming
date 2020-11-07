#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("hopscotch.in");
ofstream fout("hopscotch.out");

const int mxN=101;
const ll MOD=1e9+7;
ll dp[mxN][mxN];
int r, c, k, a[mxN][mxN];

int main(void) {
    fin >> r >> c >> k;
    for (int i=0; i<r; ++i)
        for (int j=0; j<c; ++j)
            fin >> a[i][j];
    dp[0][0]=1;
    for (int i=1; i<r; ++i) //This will probably time out but meh
        for (int j=1; j<c; ++j) //...or not I guess, pretty easy dp problem
            for (int k=0; k<i; ++k)
                for (int l=0; l<j; ++l)
                    if (a[k][l]!=a[i][j] && dp[k][l])
                        dp[i][j]=(dp[i][j]+dp[k][l])%MOD;
    fout << dp[r-1][c-1] << '\n';
}
