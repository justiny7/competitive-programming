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

ll gcd(ll a, ll b) {
    if (!b)
        return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a/gcd(a, b)*b;
}

ll get(ll LCM, ll b, ll x) {
    return ((x/LCM)*(LCM-b)+x%LCM-min(x%LCM, b-1));
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    int t;
    cin >> t;
    while (t--) {
        ll a, b, q;
        cin >> a >> b >> q;
        if (a>b)
            swap(a, b); //resets every LCM, equal for max(a, b)
        ll LCM=lcm(a, b);
        while (q--) {
            ll l, r;
            cin >> l >> r;
            cout << get(LCM, b, r)-get(LCM, b, l-1) << " ";
        }
        cout << '\n';
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

