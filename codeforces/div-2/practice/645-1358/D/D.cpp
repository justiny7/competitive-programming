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

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    ll n, x, ans=0, totdays=0; cin >> n >> x;
    vl mo(n), days(n*2), hug(n*2);
    ff0r(i, n)
        cin >> mo[i], hug[i]=hug[i+n]=mo[i]*(mo[i]+1)/2;
    ff0r(i, 2*n) {
        days[i]=mo[i%n];
        if (i) {
            days[i]+=days[i-1];
            hug[i]+=hug[i-1];
        }
    }/*
    ff0r(i, 2*n)
        cout << days[i] << " ";
    cout << '\n';
    ff0r(i, 2*n)
        cout << hug[i] << " ";
    cout << '\n';*/
    ffor(i, n, 2*n) {
        auto litr=ub(all(days), days[i]-x);
        if (litr!=beg(days)) --litr;
        ll ind=litr-beg(days), left=days[i]-days[ind]-x;
        //cout << "At month " << i%n << ", x days ago was month " << ind%n << " and we overcounted by " << left << '\n';
        ll cur=hug[i]-hug[ind]-(left*(left+1)/2);
        //cout << "We currently get " << cur << " hugs.\n";
        ckmax(ans, cur);
    }
    cout << ans << '\n';
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


