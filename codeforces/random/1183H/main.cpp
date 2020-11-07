#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=101;
const ll mxK=1e12;
ll n, k, ans, seen[256], dp[mxN][mxN];
string s;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k >> s, --k;
    dp[0][0]=1;
    memset(seen, -1, sizeof(seen));
    for (int i=1; i<=n; ++i) {
        dp[i][0]=dp[i-1][0];
        char c=s[i-1];
        for (int j=1; j<=i; ++j) {
            ll cur=dp[i-1][j-1]+dp[i-1][j];
            if (~seen[c])
                cur-=dp[seen[c]][j-1];
            dp[i][j]=min(cur, mxK);
        }
        seen[c]=i-1;
    }
    for (int i=n-1; ~i; --i) {
        ll cur=min(k, dp[n][i]);
        k-=cur, ans+=cur*(n-i);
        if (k<=0)
            return cout << ans << '\n', 0;
    }
    cout << "-1\n";
}


