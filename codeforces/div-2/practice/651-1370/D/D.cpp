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
int n, k, a[mxN];

bool works1(int x) {
    int sz=0;
    for (int i=0; i<n && sz<k; ++i) {
        if ((sz&1)==0) {
            while (a[i]>x && i<n)
                ++i;
            if (i==n)
                break;
            ++sz;
        }
        else
            ++sz;
    }
    return (sz==k);
}

bool works2(int x) {
    int sz=0;
    for (int i=0; i<n && sz<k; ++i) {
        if (sz&1) {
            while (a[i]>x && i<n)
                ++i;
            if (i==n)
                break;
            ++sz;
        }
        else
            ++sz;
    }
    return (sz==k);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    cin >> n >> k;
    ff0r(i, n)
        cin >> a[i];
    int lo=1, hi=1e9+1, best, best2;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (works1(mid)) {
            best=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    lo=1, hi=1e9+1;
    while (lo<=hi) {
        int mid=(lo+hi)/2;
        if (works2(mid)) {
            best2=mid;
            hi=mid-1;
        }
        else
            lo=mid+1;
    }
    cout << min(best, best2) << '\n';
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

