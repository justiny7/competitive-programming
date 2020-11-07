//It took like 5 submissions to realize that my is_prime function was wrong smh
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e4+1;
ll n, M, dp[mxN];

bool is_prime(ll x) {
    if (x<4)
        return 1;
    if (x%2==0)
        return 0;
    for (ll i=3; i*i<=x; i+=2)
        if (x%i==0)
            return 0;
    return 1;
}

int main() {
    ifstream cin("exercise.in");
    ofstream cout("exercise.out");
    cin >> n >> M;
    dp[0]=1;
    for (ll i=2; i<=n; ++i) {
        if (!is_prime(i))
            continue;
        vector<ll> dp2(n+1);
        for (ll j=0; j<=n; ++j)
            for (ll k=i; k+j<=n; k*=i)
                dp2[j+k]=(dp2[j+k]+dp[j]*k)%M;
        for (int j=0; j<=n; ++j)
            dp[j]=(dp[j]+dp2[j])%M;
    }
    ll ans=0;
    for (int i=0; i<=n; ++i)
        ans=(ans+dp[i])%M;
    cout << ans << '\n';
}

