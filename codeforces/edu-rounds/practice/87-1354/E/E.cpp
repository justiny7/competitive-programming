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

const int mxN=5e3+1;
int n, m, n1, n2, n3, grp[mxN], grpsize[mxN], grpcnt=1, dp[mxN][mxN];
vi adj[mxN];
pair<vi, vi> colors[mxN];
pii colcnt[mxN];
bool col[mxN], no;
map<pii, int> avail;

void dfs(int v, bool cur=0) {
    cur?++colcnt[grpcnt].fi:++colcnt[grpcnt].se;
    cur?colors[grpcnt].fi.pb(v):colors[grpcnt].se.pb(v);
    grp[v]=grpcnt, ++grpsize[grpcnt], col[v]=cur;
    in(u, adj[v]) {
        if (grp[u] && col[u]==col[v])
            no=1;
        else if (!grp[u])
            dfs(u, !cur);
        if (no)
            return;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    cin >> n >> m >> n1 >> n2 >> n3;
    ff0r(i, m) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ffor(i, 1, n+1) {
        if (!grp[i])
            dfs(i), ++grpcnt;
        if (no)
            break;
    }
    if (no) {
        cout << "NO\n";
        return 0;
    }
    dp[0][0]=1;
    ffor(i, 1, grpcnt) ff0r(j, n+1) {
        if (j-colcnt[i].fi>=0 && dp[i-1][j-colcnt[i].fi])
            dp[i][j]=1;
        if (j-colcnt[i].se>=0 && dp[i-1][j-colcnt[i].se])
            dp[i][j]=2;
    }
    if (!dp[grpcnt-1][n2]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    int c=n2;
    vi ans(n+1);
    rfor(i, 1, grpcnt) {
        if (dp[i][c]==2) {
            in(j, colors[i].fi)
                ans[j]=1;
            in(j, colors[i].se)
                ans[j]=2;
            c-=colcnt[i].se;
        }
        else {
            in(j, colors[i].fi)
                ans[j]=2;
            in(j, colors[i].se)
                ans[j]=1;
            c-=colcnt[i].fi;
        }
    }
    ffor(i, 1, n+1) {
        if (ans[i]&1 && n1>0)
            cout << 1, --n1;
        else if (ans[i]&1)
            cout << 3;
        else
            cout << 2;
    }
    cout << '\n';
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


