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

bool good(vi& a) {
    ffor(i, 1, a.size())
        if (a[i]<a[i-1])
            return 0;
    return 1;
}

int get_mex(vi& a) {
    set<int> s;
    in(i, a)
        s.ins(i);
    int cur=0;
    fitfor(it, s) {
        if (*it!=cur)
            return cur;
        ++cur;
    }
    return cur;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    int t;
    cin >> t;
    while (t--) {
        int n, k=0; cin >> n;
        bool f=0;
        vi a(n), ans;
        ff0r(i, n)
            cin >> a[i];
        set<int> done;
        while (!good(a)) {
            ++k;
            int mex=get_mex(a), pos=0;
            if (mex>=n)
                ff0r(i, n) {
                    if (!done.count(i)) {
                        pos=i;
                        break;
                    }
                }
            else
                pos=mex;
            done.ins(pos);
            a[pos]=mex;
            ans.pb(pos);
        }
        cout << k << '\n';
        in(i, ans)
            cout << i+1 << " ";
        cout << '\n';
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


