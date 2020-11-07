#include <bits/stdc++.h>
using namespace std;

const int mxN=3010;
int n, a[mxN], b[mxN], c[mxN], dp[2][mxN];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int t=0; t<3; ++t)
        for (int i=1; i<=n; ++i)
            t?(t==1?cin >> b[i]:cin >> c[i]):cin >> a[i];
    dp[0][n]=a[n], dp[1][n]=b[n];
    for (int i=n-1; i; --i) {
        dp[0][i]=max(b[i]+dp[0][i+1], a[i]+dp[1][i+1]);
        dp[1][i]=max(b[i]+dp[1][i+1], c[i]+dp[0][i+1]);
    }
    cout << dp[0][1] << '\n';
}

