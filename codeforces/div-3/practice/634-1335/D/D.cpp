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

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

const ll MOD=1e9+7;
const ll MOD2=998244353;
const int kx[]={0,1,0,-1}, ky[]={1,0,-1,0};

bool yes(int a, int b) {
    if (a==0 && b==0)
        return 1;
    if (a==1 && b==4)
        return 1;
    if (a==2 && b==8)
        return 1;
    if (a==3 && b==3)
        return 1;
    if (a==4 && b==1)
        return 1;
    if (a==5 && b==7)
        return 1;
    if (a==6 && b==5)
        return 1;
    if (a==7 && b==6)
        return 1;
    if (a==8 && b==2)
        return 1;
    return 0;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a[9][9];
        ff0r(i,9) ff0r(j,9) {
            char c;
            cin >> c;
            a[i][j]=c-'0';
        }
        ff0r(i,9) {
            ff0r(j,9) {
                if (yes(i,j))
                    cout << a[i][j]%9+1;
                else
                    cout << a[i][j];
            }
            cout << '\n';
        }
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

