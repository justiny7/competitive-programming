#include <bits/stdc++.h>
using namespace std;

const int mxN=1e3+1, M=2012;
int n, dp[mxN][mxN]; //dp[i][j] = # of possibilities at position i and j unfinished brackets
string s;

int main() {
    ifstream cin("bbreeds.in");
    ofstream cout("bbreeds.out");
    cin >> s, n=s.size();
    dp[0][0]=1;
    for (int i=1, c=0; i<=n; ++i) {
        if (s[i-1]=='(') {
            for (int j=0; j<=c; ++j)
                (dp[i][j+1]+=dp[i-1][j]+dp[i-1][c-j])%=M;
            ++c;
        }
        else {
            for (int j=1; j<=c; ++j)
                (dp[i][j-1]+=dp[i-1][j]+dp[i-1][c-j])%=M;
            --c;
        }
    }
    cout << dp[n][0] << '\n';
}

