#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define rsz resize
#define ins insert
#define mp make_pair
#define beg(x) x.begin()
#define en(x) x.end()
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ub upper_bound
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue

#define ffor(i, a, b) for (int (i)=a; i<b; ++i)
#define rfor(i, a, b) for (int (i)=b-1; i>=a; --i)
#define ff0r(i, a) for (int (i)=0; i<a; ++i)
#define rf0r(i, a) for (int (i)=a-1; i>=0; --i)
#define in(i, x) for (auto& i : x)
#define fitfor(i, x) for (auto i=(x).begin(); i!=(x).end(); ++i)
#define ritfor(i, x) for (auto i=(x).rbegin(); i!=(x).rend(); ++i)

using ll=long long;
using db=double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
using pdd=pair<db, db>;
using vi=vector<int>;
using vl=vector<ll>;
using vd=vector<db>;
using vs=vector<string>;
using vii=vector<pii>;
using vll=vector<pll>;
using vdd=vector<pdd>;

template<class T> bool ckmin(T& a, const T& b) {return (b<a)?a=b, 1:0;}
template<class T> bool ckmax(T& a, const T& b) {return (a<b)?a=b, 1:0;}

const ll MOD=1e9+7;
const ll MOD2=998244353;
const int kx[]={0,1,0,-1}, ky[]={1,0,-1,0};

void fileIO(string filename) {
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

const int mxN=5e5+1;
ll n, k, fact[mxN];

void get_fact() {
    fact[0]=1;
    ffor(i, 1, mxN)
        fact[i]=fact[i-1]*i%MOD2;
}

ll binpow(ll a, ll b) {
    ll ans=1;
    while (b>0) {
        if (b&1)
            ans=ans*a%MOD2;
        a=a*a%MOD2;
        b>>=1;
    }
    return ans;
}

ll inv(ll a) {
    return binpow(a, MOD2-2);
}

ll choose(ll n, ll k) {
    return fact[n]*inv(fact[k])%MOD2*inv(fact[n-k])%MOD2;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    cin >> n >> k;
    if (n<k) {
        cout << "0\n";
        return 0;
    }
    get_fact();
    ll ans=0;
    ffor(i, 1, n+1) {
        if (n/i-1>=k-1)
            ans=(ans+choose(n/i-1, k-1))%MOD2;
        else
            break;
    }
    cout << ans << '\n';
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


