#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define rsz resize
#define ins insert
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue

#define in(i, x) for (auto& (i):(x))
#define FIT(i, x) for (auto (i)=(x).begin(); (i)!=(x).end(); ++(i))
#define RIT(i, x) for (auto (i)=(x).rbegin(); (i)!=(x).rend(); ++(i))
#define finish(x) return print(x), 0

using ll=long long;
//using db=double;
using ld=long double;
using pii=pair<int, int>;
using pll=pair<ll, ll>;
//using pdd=pair<db, db>;
using vi=vector<int>;
using vl=vector<ll>;
//using vd=vector<db>;
using vs=vector<string>;
using vii=vector<pii>;
using vll=vector<pll>;
//using vdd=vector<pdd>;

template<class T> using mqueue=pqueue<T, vector<T>, greater<T>>;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T& a, const T& b) { return (b<a)?a=b, 1:0; }
template<class T> bool ckmax(T& a, const T& b) { return (a<b)?a=b, 1:0; }

template<class T> void read(T& x) { cin >> x; }
template<class H, class T> void read(pair<H, T>& p) { cin >> p.fi >> p.se; }
template<class T> void read(vector<T>& v) { in(i, v) read(i); }
template<class H, class... T> void read(H& h, T&... t) { read(h); read(t...); }

template<class H, class T> ostream& operator<<(ostream& o, const pair<H, T> &p) { o << p.fi << " " << p.se; return o; }
template<class T> ostream& operator<<(ostream& o, vector<T> &v) { bool f=0; in(i, v) o << (f?" ":"") << i, f=1; return o; }
template<class H, class T> ostream& operator<<(ostream& o, vector<pair<H, T>> &v) { bool f=0; in(i, v) o << (f?"\n":"") << i, f=1; return o; }
template<class T> ostream& operator<<(ostream& o, vector<vector<T>> &v) { bool f=0; in(i, v) o << (f?"\n":"") << i, f=1; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H& h, const T&... t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H& h, const T&... t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

const ll M=1e9+7; //998244353;
const int kx[]={0,1,0,-1}, ky[]={1,0,-1,0};

const int mxN=1e5+1, INF=0x3f3f3f3f;
int n, a, b, da, db, dist[mxN], mxn, mxl;
vi adj[mxN];
bool done;

void dfs(int v=a, int c=0, int f=1, int p=0) {
    if (v==b && f && c<=da) {
        print("Alice");
        done=1;
    }
    if (c>mxl)
        mxl=c, mxn=v;
    ckmax(dist[v], c);
    for (int u:adj[v])
        if (u^p)
            dfs(u, c+1, f, v);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        read(n, a, b, da, db);
        for (int i=1; i<=n; ++i)
            adj[i].clear(), dist[i]=0;
        done=0;
        for (int i=1; i<n; ++i) {
            int x, y;
            read(x, y);
            adj[x].pb(y);
            adj[y].pb(x);
        }
        if (db<=da*2) {
            print("Alice");
            continue;
        }
        mxl=-1;
        dfs();
        if (done)
            continue;
        mxl=-1;
        dfs(mxn, 0, 0);
        int mx=0;
        for (int i=1; i<=n; ++i)
            ckmax(mx, dist[i]);
        ++mx;
        if (da<mx/2)
            print("Bob");
        else
            print("Alice");
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

