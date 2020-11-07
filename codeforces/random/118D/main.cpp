#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=101;
const ll M=1e8;
int n1, n2, k1, k2;
ll dp[mxN][mxN][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n1 >> n2 >> k1 >> k2;
    dp[0][0][0]=dp[0][0][1]=1;
    for (int i=0; i<=n1; ++i)
        for (int j=0; j<=n2; ++j) {
            for (int k=1; k<=k1; ++k)
                if (i-k>=0)
                    dp[i][j][0]=(dp[i][j][0]+dp[i-k][j][1])%M;
            for (int k=1; k<=k2; ++k)
                if (j-k>=0)
                    dp[i][j][1]=(dp[i][j][1]+dp[i][j-k][0])%M;
        }
    cout << (dp[n1][n2][0]+dp[n1][n2][1])%M << '\n';
}

