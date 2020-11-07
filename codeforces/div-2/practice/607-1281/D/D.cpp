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

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vs a(n); bool f=1, done=1;
        ff0r(i, n) {
            cin >> a[i];
            if (count(all(a[i]), 'A'))
                f=0;
            if (count(all(a[i]), 'P'))
                done=0;
        }
        if (done) {
            cout << "0\n";
            continue;
        }
        if (f) {
            cout << "MORTAL\n";
            continue;
        }
        int s1=0, s2=0, s3=0, s4=0;
        ff0r(i, m) {
            if (a[0][i]=='A')
                ++s1;
            if (a[n-1][i]=='A')
                ++s2;
        }
        if (s1==m || s2==m) {
            cout << "1\n";
            continue;
        }
        ff0r(i, n) {
            if (a[i][0]=='A')
                ++s3;
            if (a[i][m-1]=='A')
                ++s4;
        }
        if (s3==n || s4==n) {
            cout << "1\n";
            continue;
        }
        if (a[0][0]=='A' || a[0][m-1]=='A' || a[n-1][0]=='A' || a[n-1][m-1]=='A') {
            cout << "2\n";
            continue;
        }
        f=0;
        ffor(i, 1, n-1) {
            if (count(all(a[i]), 'A')==m) {
                f=1;
                break;
            }
        }
        if (f) {
            cout << "2\n";
            continue;
        }
        ffor(i, 1, m-1) {
            int cur=0;
            ff0r(j, n)
                if (a[j][i]=='A')
                    ++cur;
            if (cur==n) {
                f=1;
                break;
            }
        }
        if (f) {
            cout << "2\n";
            continue;
        }
        if (s1 || s2 || s3 || s4) {
            cout << "3\n";
            continue;
        }
        cout << "4\n";
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


