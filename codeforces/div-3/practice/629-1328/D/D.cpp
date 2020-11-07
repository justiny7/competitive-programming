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
    int q;
    cin >> q;
    while (q--) {
        int n; cin >> n;
        vi t(n);
        set<int> s;
        ff0r(i, n) {
            cin >> t[i];
            s.ins(t[i]);
        }
        if (sz(s)==1) {
            cout << "1\n";
            ff0r(i, n)
                cout << "1 ";
            cout << '\n';
            continue;
        }
        if (n&1) {
            vi ans;
            ans.pb(1);
            bool f=1, w=1;
            ffor(i, 1, n-1) {
                if (t[i]==t[i-1] && w) {
                    ans.pb(ans.back());
                    w=0;
                }
                else {
                    ans.pb((f?2:1));
                    f=!f;
                }
            }
            if (ans.back()==1) {
                ans.pb(2);
                cout << "2\n";
            }
            else if (ans.back()==2) {
                if (n>2 && t[n-1]==t[n-2]) {
                    ans.pb(2);
                    cout << "2\n";
                }
                else if (t[n-1]==t[0]) {
                    ans.pb(1);
                    cout << "2\n";
                }
                else {
                    ans.pb(3);
                    cout << "3\n";
                }
            }
            in(i, ans) cout << i << " ";
            cout << '\n';
            continue;
        }
        cout << "2\n";
        ff0r(i, n)
            cout << ((i&1)?2:1) << " ";
        cout << '\n';
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


