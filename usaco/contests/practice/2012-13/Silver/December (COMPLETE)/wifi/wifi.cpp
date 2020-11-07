//Yay worked first try
//An ok dp problem ig
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e3+1;
ll n, a, b, x[mxN], dp[mxN];

int main() {
    memset(dp, 0x3f, sizeof(dp));
    ifstream cin("wifi.in");
    ofstream cout("wifi.out");
    cin >> n >> a >> b;
    for (int i=0; i<n; ++i)
        cin >> x[i];
    sort(x, x+n);
    dp[0]=0;
    for (int i=1; i<=n; ++i)
        for (int j=0; j<i; ++j)
            dp[i]=min(dp[i], dp[j]+a*2+b*(x[i-1]-x[j])); //*2 to account for decimal
    cout << dp[n]/2 << ((dp[n]&1)?".5":"") << '\n';
}

