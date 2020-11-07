#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e6+1, MOD=1e9+7;
ll fact[mxN];
string s;
map<int, ll> mp;

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

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    get_fact();
    cin >> s;
    for (char c:s)
        ++mp[int(c-'a')];
    ll ans=fact[s.size()];
    for (auto& p:mp)
        ans=ans*inv(fact[p.second])%MOD;
    cout << ans << '\n';
}
