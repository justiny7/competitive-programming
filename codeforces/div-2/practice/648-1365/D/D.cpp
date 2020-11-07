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

bool IN(int a, int b, int n, int m) {
    return (a<n && b<m && a>=0 && b>=0);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vs a(n);
        int g=0;
        ff0r(i, n) {
            cin >> a[i];
            g+=count(all(a[i]), 'G');
        }
        if (!g) {
            cout << "Yes\n";
            continue;
        }
        bool f=0;
        ff0r(i, n) {
            ff0r(j, m) {
                if (a[i][j]!='B')
                    continue;
                ff0r(k, 4) {
                    int y=i+ky[k], x=j+kx[k];
                    if (IN(y, x, n, m) && ((y==n-1 && x==m-1) || a[y][x]=='G')) {
                        f=1;
                        break;
                    }
                    else if (IN(y, x, n, m) && a[y][x]=='.')
                        a[y][x]='#';
                }
                if (f)
                    break;
            }
            if (f)
                break;
        }
        if (f) {
            cout << "No\n";
            continue;
        }
        assert(a[n-1][m-1]=='.');
        queue<pii> q;
        q.push({n-1, m-1});
        a[n-1][m-1]='#';
        int gcnt=0;
        while (!q.empty()) {
            int y=q.front().fi, x=q.front().se;
            q.pop();
            ff0r(i, 4) {
                int ny=y+ky[i], nx=x+kx[i];
                if (IN(ny, nx, n, m) && a[ny][nx]!='#') {
                    gcnt+=a[ny][nx]=='G';
                    a[ny][nx]='#';
                    q.push({ny, nx});
                }
            }
        }
        if (gcnt==g)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


