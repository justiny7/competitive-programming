#include <bits/stdc++.h>
using namespace std;

const int mxN=3e3+1;
int n, m, dp[mxN][mxN];
string s, t, ans;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> t;
    n=s.size(), m=t.size();
    for (int i=1; i<=n; ++i)
        for (int j=1; j<=m; ++j) {
            if (s[i-1]==t[j-1])
                dp[i][j]=max(dp[i][j], 1+dp[i-1][j-1]);
            else
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    int i=n, j=m;
    while (i && j) {
        if (s[i-1]==t[j-1])
            ans.push_back(s[i-1]), --i, --j;
        else if (dp[i-1][j]>dp[i][j-1])
            --i;
        else
            --j;
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}
