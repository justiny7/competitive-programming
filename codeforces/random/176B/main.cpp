#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1, M=1e9+7;
string s, t;
long long k, dp[2][mxN]; //dp[0]->not equal to t, dp[1]=equal to t

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> t >> k;
    int n=s.size(), ok=0, nok=0;
    dp[0][0]=(s==t), dp[1][0]=1^dp[0][0];
    for (int i=0; i<n; ++i) {
        if (s==t)
            ++ok;
        else
            ++nok;
        rotate(s.begin(), s.begin()+1, s.end());
    }
    for (int i=1; i<=k; ++i) {
        dp[0][i]=(dp[0][i-1]*(ok-1)%M+dp[1][i-1]*ok%M)%M;
        dp[1][i]=(dp[1][i-1]*(nok-1)%M+dp[0][i-1]*nok%M)%M;
    }
    cout << dp[0][k] << '\n';
}

