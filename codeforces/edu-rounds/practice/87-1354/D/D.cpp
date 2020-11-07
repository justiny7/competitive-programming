#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define rsz resize
//#define ins insert
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

void upd(int i, int add, vi& bit) {
    while (i>0 && i<sz(bit))
        bit[i]+=add, i=i+(i&(-i));
}

int sum(int i, vi& bit) {
    int ans=0;
    while (i>0)
        ans+=bit[i], i=i-(i&(-i));
    return ans;
}

int find(int k, vi& bit) {
    int lo=0, hi=sz(bit);
    while (lo<hi) {
        int mid=lo+(hi-lo)/2;
        if (k<=sum(mid, bit)) hi=mid;
        else lo=mid+1;
    }
    return lo;
}

void ins(int a, vi& bit) {
    upd(a, 1, bit);
}

void del(int a, vi& bit) {
    upd(a, -1, bit);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    int n, q; cin >> n >> q;
    vi bit(n);
    ff0r(i, n) {
        int a; cin >> a;
        ins(a, bit);
    }
    int a=0, d=0;
    ff0r(i, q) {
        int x; cin >> x;
        if (x>0)
            ins(x, bit), ++a;
        else
            del(find(-x, bit), bit), ++d;
    }
    if (n+a-d>0)
        cout << find(1, bit) << '\n';
    else
        cout << "0\n";
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


