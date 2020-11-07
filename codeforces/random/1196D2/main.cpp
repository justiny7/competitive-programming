#include <bits/stdc++.h>
using namespace std;

const string str="RGB";

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        vector<vector<int>> dp(n+1, vector<int>(3));
        for (int i=0; i<n; ++i)
            for (int j=0; j<3; ++j)
                dp[i+1][j]=(s[i]!=str[(i+j)%3]?1:0)+dp[i][j];
        int ans=INT_MAX;
        for (int i=k; i<=n; ++i)
            for (int j=0; j<3; ++j)
                ans=min(ans, dp[i][j]-dp[i-k][j]);
        cout << ans << '\n';
    }
}

