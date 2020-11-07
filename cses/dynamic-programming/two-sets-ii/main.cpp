#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int MOD=1e9+7;
ll n, dp[100001];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n*(n+1)%4>0) {
        cout << "0\n";
        return 0;
    }
    ll t=n*(n+1)/4;
    dp[1]=1;
    for (int i=2; i<=n; ++i)
        for (int j=t; j>0; --j)
            if (j-i>0)
                dp[j]=(dp[j]+dp[j-i])%MOD;
    cout << dp[t] << '\n';
}

