#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ifstream fin("hopscotch.in");
ofstream fout("hopscotch.out");

int r, c;
string a[15];
ll dp[15][15];

int main(void) {
    fin >> r >> c;
    for (int i=0; i<r; ++i)
        fin >> a[i];
    dp[0][0]=1;
    for (int i=1; i<r; ++i)
        for (int j=1; j<c; ++j)
            for (int k=0; k<i; ++k)
                for (int l=0; l<j; ++l)
                    if (a[k][l]!=a[i][j])
                        dp[i][j]+=dp[k][l];
    fout << dp[r-1][c-1] << '\n';
}

