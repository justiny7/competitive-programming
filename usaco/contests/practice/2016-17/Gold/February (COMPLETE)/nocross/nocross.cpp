#include <bits/stdc++.h>
using namespace std;
//OMFG I spend so long on this and in the end the solution was so simple
//I overthought this problem so hard - at least I didn't look at sol
ifstream fin("nocross.in");
ofstream fout("nocross.out");

const int mxN=1e3+1;
int n, a[mxN], b[mxN], dp[mxN][mxN];

int main() {
    fin >> n;
    for (int i=1; i<=n; ++i)
        fin >> a[i];
    for (int i=1; i<=n; ++i)
        fin >> b[i];
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
            dp[i][j]=max({dp[i][j], dp[i-1][j-1]+(abs(a[i]-b[j])<=4), dp[i-1][j], dp[i][j-1]});
    fout << dp[n][n] << '\n';
}
