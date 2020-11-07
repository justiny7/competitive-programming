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

const int mxN=2e5+1;
int n;
ll a[mxN], seg[mxN*4];

void build(int v=1, int l=0, int r=n-1) {
    if (l==r)
        seg[v]=a[l];
    else {
        int mid=(l+r)/2;
        build(v*2, l, mid);
        build(v*2+1, mid+1, r);
        seg[v]=min(seg[v*2], seg[v*2+1]);
    }
}

ll get(int l, int r, int li=0, int ri=n-1, int v=1) {
    if (l>r)
        return LLONG_MAX;
    if (li==l &&  ri==r)
        return seg[v];
    int mid=(li+ri)/2;
    return min(get(l, min(r, mid), li, mid, v*2), get(max(l, mid+1), r, mid+1, ri, v*2+1));
}

void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r)
        seg[v]=x;
    else {
        int mid=(l+r)/2;
        if (i<=mid)
            upd(i, x, l, mid, v*2);
        else
            upd(i, x, mid+1, r, v*2+1);
        seg[v]=min(seg[v*2], seg[v*2+1]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    cin >> n;
    ff0r(i, n)
        cin >> a[i];
    build();
    int cnt=n/2;
    while (cnt>0) {
        int smol=get(0, n-1);
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


