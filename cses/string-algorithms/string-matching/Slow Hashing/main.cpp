//This is probably gonna get hacked but oh well
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

const ll M=1e9+7, P=31, M2=1e9+9, P2=43;
ll n, m, target, target2;
string s, t;
vector<ll> hsh, power, inv, hsh2, power2, inv2;

ll binpow(ll a, ll b, ll MOD) {
    ll ans=1;
    while (b) {
        if (b&1)
            ans=ans*a%MOD;
        a=a*a%MOD, b>>=1;
    }
    return ans;
}

void get_power() {
    power.pb(1);
    for (int i=0; i<n; ++i)
        power.pb(power.back()*P%M);
    power2.pb(1);
    for (int i=0; i<n; ++i)
        power2.pb(power2.back()*P2%M2);
}

void get_inv() {
    for (int i=0; i<power.size(); ++i)
        inv.pb(binpow(power[i], M-2, M));
    for (int i=0; i<power2.size(); ++i)
        inv2.pb(binpow(power2[i], M2-2, M2));
}

void get_hash() {
    hsh.pb(0);
    for (int i=0; i<n; ++i)
        hsh.pb((hsh.back()+(s[i]-'a'+1)*power[i])%M);
    hsh2.pb(0);
    for (int i=0; i<n; ++i)
        hsh2.pb((hsh2.back()+(s[i]-'a'+1)*power2[i])%M2);
}

ll hash_sect(int st) {
    int en=st+m;
    return (((hsh[en]-hsh[st])*inv[st]%M)+M)%M;
}

ll hash_sect2(int st) {
    int en=st+m;
    return (((hsh2[en]-hsh2[st])*inv2[st]%M2)+M2)%M2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> t;
    n=s.size(), m=t.size();
    get_power();
    get_inv();
    get_hash();
    for (int i=0; i<m; ++i) {
        target=(target+(t[i]-'a'+1)*power[i])%M;
        target2=(target2+(t[i]-'a'+1)*power2[i])%M2;
    }
    int ans=0;
    for (int i=0; i<n; ++i)
        if (hash_sect(i)==target && hash_sect2(i)==target2)
            ++ans;
    cout << ans << '\n';
}
