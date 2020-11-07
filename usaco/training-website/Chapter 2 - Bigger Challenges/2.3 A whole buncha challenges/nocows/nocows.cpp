/*
ID: justiny7
LANG: C++
TASK: nocows
*/

#include <bits/stdc++.h>
#define MOD 9901
using namespace std;

ifstream fin("nocows.in");
ofstream fout("nocows.out");

int n, k, dp[101][201]; //dp[a][b] = ways to make a tree with height a and b nodes

int main(void) {
    fin >> n >> k;
    for (int i = 1; i <= k; i++)
        dp[i][1] = 1;
    for (int h = 2; h <= k; h++)
        for (int i = 1; i <= n; i += 2)
            for (int j = 1; j < i-1; j += 2) {
                dp[h][i] += (dp[h-1][j]*dp[h-1][i-1-j]);
                dp[h][i] %= MOD;
            }
    fout << (dp[k][n]-dp[k-1][n]+MOD)%MOD << '\n';
    return 0;
}
