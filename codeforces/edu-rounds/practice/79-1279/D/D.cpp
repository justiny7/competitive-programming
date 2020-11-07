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

ll modinv(ll a) {
    return binpow(a, MOD2-2);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    int n; cin >> n;
    ll ans=0;
    map<int, vi> kids;
    map<int, int> gifts;
    vll probs;
    ff0r(i, n) {
        int a; cin >> a;
        kids[i].rsz(a);
        ff0r(j, a) {
            int b; cin >> b;
            kids[i][j]=b;
            ++gifts[b];
        }
    }
    ll invN=modinv(n);
    in(i, kids) in(j, i.se) {
        ll a=gifts[j], b=sz(i.se);
        ans=(ans+(1LL*(1LL*invN*modinv(b)%MOD2)*(1LL*invN*a%MOD2))%MOD2)%MOD2;
    }
    cout << ans << '\n';

    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


