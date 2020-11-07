//Ayy rolling polynomial hash+binsearch worked!
//Got it second try - first time, I forgot to clear the set
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll=long long;

ifstream fin("cownomics.in");
ofstream fout("cownomics.out");

const int mxN=501;
const ll P=31, M=1e9+7;
int n, m;
vector<ll> s_hash[mxN], p_hash[mxN], power, inv;

vector<ll> get_hash(string s) {
    vector<ll> hash={0LL};
    for (int i=0; i<m; ++i)
        hash.pb((hash.back()+(s[i]-'A'+1)*power[i])%M);
    return hash;
}

ll binpow(ll a, ll b) {
    ll ans=1;
    while (b) {
        if (b&1)
            ans=ans*a%M;
        a=a*a%M, b>>=1;
    }
    return ans;
}

ll modinv(int a) {
    return binpow(power[a], M-2);
}

ll hash_sect(vector<ll>& hash, int st, int len) {
    int en=st+len;
    return (((hash[en]-hash[st])*inv[st]%M)+M)%M;
}

bool works(int x) {
    set<ll> taken;
    for (int j=0; j+x<=m; ++j) {
        for (int i=0; i<n; ++i)
            taken.insert(hash_sect(s_hash[i], j, x));
        bool f=0;
        for (int i=0; i<n; ++i)
            if (taken.count(hash_sect(p_hash[i], j, x))) {
                f=1;
                break;
            }
        if (!f)
            return 1;
        taken.clear();
    }
    return 0;
}

int main() {
    fin >> n >> m;
    power.pb(1);
    for (int i=0; i<m; ++i)
        power.pb(power.back()*P%M);
    for (int i=0; i<power.size(); ++i)
        inv.pb(modinv(i));
    for (int i=0; i<n; ++i) {
        string s; fin >> s;
        s_hash[i]=get_hash(s);
    }
    for (int i=0; i<n; ++i) {
        string s; fin >> s;
        p_hash[i]=get_hash(s);
    }
    int lo=1, hi=m;
    while (lo<hi) {
        int mid=(lo+hi)/2;
        if (works(mid))
            hi=mid;
        else
            lo=mid+1;
    }
    fout << lo << '\n';
}
