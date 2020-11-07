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

const int mxN=1e5+1;
int n, dp[3][mxN]; //0=didn't fell, 1=left, 2=right
pii trees[mxN];

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    if (n<3) {
        cout << n << '\n';
        return 0;
    }
    ff0r(i, n)
        cin >> trees[i].fi >> trees[i].se;
    dp[0][0]=0, dp[1][0]=1;
    if (trees[0].fi+trees[0].se<trees[1].fi)
        dp[2][0]=1;
    ffor(i, 1, n-1) {
        if (trees[i].fi-trees[i].se>trees[i-1].fi)
            dp[1][i]=max(dp[0][i-1], dp[1][i-1])+1;
        if (dp[2][i-1]>0 && trees[i].fi-trees[i].se>trees[i-1].fi+trees[i-1].se)
            ckmax(dp[1][i], dp[2][i-1]+1);
        if (trees[i].fi+trees[i].se<trees[i+1].fi)
            dp[2][i]=max({dp[0][i-1], dp[1][i-1], dp[2][i-1]})+1;
        dp[0][i]=max({dp[0][i-1], dp[1][i-1], dp[2][i-1]});
    }
    int ans=0;
    ff0r(i, 3)
        ckmax(ans, dp[i][n-2]);
    cout << ans+1 << '\n';
    //fileIO("");
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


