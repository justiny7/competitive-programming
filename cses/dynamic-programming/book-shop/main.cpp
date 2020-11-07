#include <bits/stdc++.h>
using namespace std;

int n, x, dp[100001], h[1001], s[1001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> x;
    for (int i=0; i<n; ++i)
        cin >> h[i];
    for (int i=0; i<n; ++i)
        cin >> s[i];
    for (int i=0; i<n; ++i)
        for (int j=x; j-h[i]>=0; j--)
            dp[j]=max(dp[j], dp[j-h[i]]+s[i]);
    cout << dp[x] << '\n';
}
