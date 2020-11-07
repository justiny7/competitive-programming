#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

//It took me like 7 tries longer that it should've because I forgot a pair of parenthesis -_-
//At least I learned rolling polynomial hash
ifstream fin("censor.in");
ofstream fout("censor.out");

const int mxN=1e6+1;
const ll p=31, MOD=1e9+7;
vector<ll> s_hash, power;
string s, t, str;
int n, x;

ll hash1(string s) {
    ll ans=0, pp=1;
    for (char c:s) {
        ans=(ans+(c-'a'+1)*pp)%MOD;
        pp=pp*p%MOD;
    }
    return ans;
}

ll binpow(ll a, ll b) {
    ll ans=1;
    while (b>0) {
        if (b&1)
            ans=ans*a%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return ans;
}

ll inv(int a) {
    return binpow(power[a], MOD-2);
}

int main(void) { //AHHH good thing I've been practicing Codeforces so I know some stuff about modular inverses
    fin >> s >> t;
    n=s.size(), x=t.size();
    ll target=hash1(t);
    power.pb(1);
    s_hash.pb(0);
    for (int i=0; i<n; ++i) {
        s_hash.pb((s_hash.back()+(s[i]-'a'+1)*power.back())%MOD);
        power.pb(power.back()*p%MOD);
        str.pb(s[i]);
        int sz=str.size();
        if (sz>=x) {
            ll hsh=(((s_hash.back()-s_hash[sz-x])*inv(sz-x)%MOD)+MOD)%MOD;
            if (hsh==target && str.substr(sz-x)==t) {
                str.resize(sz-x);
                s_hash.resize(sz-x+1);
                power.resize(sz-x+1);
            }
        }
    }
    fout << str << '\n';
}
