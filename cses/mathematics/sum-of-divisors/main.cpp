/*
 * The answer is the summation of i*floor(n, i) for all i from 1 to n.
 * Since there can only be sqrt(n) distinct values of floor(n, i), we
 * first find the sum of all individual values of floor(n, i)*i up to
 * sqrt(n). Then, for each i from 1 to sqrt(n), add in the ranges from
 * sqrt(n) to n in which the divisors in that range appear i times - the
 * range from (floor(n, i+1), floor(n, i)]
*/

#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using ll=long long;

const ll MOD=1e9+7;
ll n, ans;

ll sum(ll x) {
    x%=MOD;                               //returns sum from 1 to x mod MOD: x*(x+1)*(modinv(2))
    return (((x+1)*x%MOD)*(MOD+1)/2)%MOD; //((MOD+1)/2 is modular multiplicative inverse of 2)
}

int main(void) {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (ll i=1; i*i<=n; ++i) {
        if (i!=n/i)
            ans=(ans+n/i*i)%MOD;
        ans=(ans+(sum(n/i)-sum(n/(i+1)))*i)%MOD; //sum of range floor(n/i) to floor(n/(i+1)) times i
    }
    cout << ans << '\n';
}
