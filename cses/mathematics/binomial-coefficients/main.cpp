#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e6+1, MOD=1e9+7;
ll n, fact[mxN];

void get_fact() {
    fact[0]=1;
    for (int i=1; i<mxN; ++i)
        fact[i]=fact[i-1]*i%MOD;
}

ll binpow(ll a, ll b) {
    ll ans=1;
    while (b) {
        if (b&1)
            ans=ans*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ans;
}

ll inv(ll a) {
    return binpow(a, MOD-2);
}

ll choose(ll n, ll k) {
    return (fact[n]*inv(fact[k])%MOD*inv(fact[n-k])%MOD)%MOD;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    get_fact();
    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << choose(a, b) << '\n';
    }
}
