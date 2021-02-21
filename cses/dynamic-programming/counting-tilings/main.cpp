#include <bits/stdc++.h>
using namespace std;

const int mxN=10, M=1e9+7;
int n, m, dp[1<<mxN][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    dp[0][0]=1;
    for (int j=0; j<m; ++j) {
        for (int i=0; i<n; ++i) {
            for (int k=0; k<(1<<n); ++k) {
                dp[k][1]=dp[k^(1<<i)][0];
                if (i && !(k&(1<<i)) && !(k&(1<<i-1)))
                    (dp[k][1]+=dp[k^(1<<i-1)][0])%=M;
            }
            for (int k=0; k<(1<<n); ++k)
                dp[k][0]=dp[k][1];
        }
    }
    cout << dp[0][0] << '\n';
}

