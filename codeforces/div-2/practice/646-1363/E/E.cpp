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
int n, t, have[mxN], want[mxN];
ll ans=0, cost[mxN];
vi adj[mxN];

void dfs(int v=1, int par=0) {
    if (v>1)
        ckmin(cost[v], cost[par]);
    in(u, adj[v])
        if (u!=par)
            dfs(u, v);
}

pii dfs2(int v=1, int par=0) {
    pii cur=mp(0, 0);
    if (have[v]!=want[v])
        cur.fi+=have[v], cur.se+=want[v];
    in(u, adj[v])
        if (u!=par) {
            pii temp=dfs2(u, v);
            cur.fi+=temp.fi, cur.se+=temp.se;
        }
    int smol=min(cur.fi, cur.se);
    ans+=cost[v]*smol*2, cur.fi-=smol, cur.se-=smol;
    return cur;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //fileIO("");
    cin >> n;
    pii zeros=mp(0, 0), ones=mp(0, 0);
    ffor(i, 1, n+1) {
        cin >> cost[i] >> have[i] >> want[i];
        if (have[i])
            ++ones.fi;
        else
            ++zeros.fi;
        if (want[i])
            ++ones.se;
        else
            ++zeros.se;
    }
    if (zeros.fi!=zeros.se || ones.fi!=ones.se) {
        cout << "-1\n";
        return 0;
    }
    ff0r(i, n-1) {
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    dfs2();
    cout << ans << '\n';
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


