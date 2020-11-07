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

pii getvals(ll l, ll n) {
    ll a, b;
    if (l==n*(n-1)+1) {
        a=b=n+1;
        return mp(a, b);
    }
    ll k=1, cur=0;
    while (cur<l)
        cur+=2*(n-k++);
    a=k-1, cur-=2*(n-a), b=a+(l-cur+1)/2;
    return mp(a, b);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    int t;
    cin >> t;
    while (t--) {
        ll n, l, r, cnt; cin >> n >> l >> r;
        cnt=r-l+1;
        ll a, b;
        bool f=1;
        pii p=getvals(l, n);
        a=p.fi, b=p.se;
        //cout << a << " " << b << '\n';
        for (int i=a; i<=n && cnt; ++i)
            for (int j=(f?b:i+1); j<=n && cnt; ++j) {
                if (f && l%2==0) {
                    if (cnt>1)
                        cout << j << " ";
                    else
                        cout << j << '\n';
                    f=0, --cnt;
                    continue;
                }
                f=0;
                if (cnt>2) {
                    cout << i << " " << j << " ";
                    cnt-=2;
                }
                else if (cnt==2) {
                    cout << i << " " << j << '\n';
                    cnt=0;
                }
                else if (cnt==1) {
                    cout << i << '\n';
                    cnt=0;
                }
            }
        if (cnt)
            cout << "1\n";
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


