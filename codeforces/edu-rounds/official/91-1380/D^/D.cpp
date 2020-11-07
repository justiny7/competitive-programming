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
template<class T> using min_heap=pqueue<T, vector<T>, greater<T>>;

template<class T> bool ckmin(T& a, const T& b) {return (b<a)?a=b, 1:0;}
template<class T> bool ckmax(T& a, const T& b) {return (a<b)?a=b, 1:0;}

const ll MOD=1e9+7;
const ll MOD2=998244353;
const int kx[]={0,1,0,-1}, ky[]={1,0,-1,0};

void fileIO(string filename) {
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

int n, m, x, k, y;
ll ans;
vl a, b, inds;

bool good() {
    int i=1, j=1;
    inds.pb(0);
    while (i<=n && j<=m) {
        if (a[i]==b[j])
            ++j, inds.pb(i);
        ++i;
    }
    if (j<=m)
        cout << "-1\n";
    return (j>m);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    cin >> n >> m >> x >> k >> y;
    if (m>n) {
        cout << "-1\n";
        return 0;
    }
    a.rsz(n+1); b.rsz(m+1);
    ffor(i, 1, n+1) cin >> a[i];
    ffor(i, 1, m+1) cin >> b[i];
    if (m==n) {
        if (a==b)
            cout << "0\n";
        else
            cout << "-1\n";
        return 0;
    }
    if (!good())
        return 0;
    inds.pb(n+1);
    int s=inds.size();
    for (int i=1; i<s; ++i) {
        ll d=inds[i]-inds[i-1]-1;
        if (!d)
            continue;
        ll cmax=0, cur=0, l=a[inds[i-1]], r=a[inds[i]];
        for (int j=inds[i-1]+1; j<inds[i]; ++j)
            ckmax(cmax, a[j]);
        if (cmax>l && cmax>r && d<k) {
            cout << "-1\n";
            return 0;
        }
        cur+=y*(d%k), d-=d%k;
        ll add=x*d/k;
        if (cmax<=l || cmax<=r)
            ckmin(add, y*d);
        else
            ckmin(add, x+y*(d-k));
        ans+=cur+add;
    }
    cout << ans << '\n';
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


