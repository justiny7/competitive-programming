#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const ll MOD=1e9+7;
map<ll, ll> dp;

ll fib(ll n) {
    if (dp.count(n))
        return dp[n];
    dp[n]=(((fib((n+1)/2)*fib(n/2))%MOD+(fib((n-1)/2)*fib((n-2)/2)%MOD))%MOD);
    return dp[n];
}

int main(void) {
    dp[0]=1;
    dp[1]=1;
    ll n; cin >> n;
    if (n==0) {
        cout << "0\n";
        return 0;
    }
    cout << fib(n-1) << '\n';
}
