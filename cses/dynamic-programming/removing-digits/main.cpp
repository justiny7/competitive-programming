#include <bits/stdc++.h>
using namespace std;

int n, dp[1000001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    fill(dp, dp+n, 1e9);
    for (int i=n; i>=0; i--) {
        string s=to_string(i);
        if (dp[i]==1e9)
            continue;
        for (int j=0; j<s.length(); j++)
            if (i-(s[j]-'0')>=0)
                dp[i-(s[j]-'0')]=min(dp[i-(s[j]-'0')], dp[i]+1);
    }
    cout << dp[0] << '\n';
}
