#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//Utilities
#define fi first
#define se second
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define finish(...) return void(print(__VA_ARGS__))

//Loops
#define IN(i, x) for (auto &(i):(x))
#define FIT(i, x) for (auto (i)=(x).begin(); (i)!=(x).end(); ++(i))
#define RIT(i, x) for (auto (i)=(x).rbegin(); (i)!=(x).rend(); ++(i))

//Data types
using ll=long long;
using db=double;
using ld=long double;

using pii=pair<int, int>;
using pll=pair<ll, ll>;
using pdd=pair<db, db>;

using vi=vector<int>;
using vl=vector<ll>;
using vd=vector<db>;
using vb=vector<bool>;
using vs=vector<string>;

using vii=vector<pii>;
using vll=vector<pll>;
using vdd=vector<pdd>;

template<class T> using pqueue=priority_queue<T>;
template<class T> using mqueue=priority_queue<T, vector<T>, greater<T>>;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Input
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.fi >> p.se; }
template<class T, size_t S> void read(array<T, S> &a) { IN(i, a) read(i); }

template<class T> void read(vector<T> &v) { IN(i, v) read(i); }
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

//Output
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.fi << " " << p.se; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; IN(i, a) o << s << i, s=" "; return o; }

template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; IN(i, v) o << s << i, s=" "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

//More utilities
template<class T> bool ckmin(T &a, const T &b) { return (b<a?a=b, 1:0); }
template<class T> bool ckmax(T &a, const T &b) { return (a<b?a=b, 1:0); }

//Constants
const ll M=1e9+7; //998244353;
const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int mxN=2e5+10;
int n, m;
vi adj[mxN]; //v*2 -> change this node, v*2+1 -> don't change this node
vector<vi> a;
vb vis, add;

inline bool in(int y, int x) {
    return (y>=0 && x>=0 && y<n && x<m);
}
void dfs(int v) {
    vis[v/2]=1;
    if (v%2==0) {
        int nd=v/2;
        if (!add[v])
            a[nd/m][nd%m]+=(add[v]=1);
    }
    for (int u:adj[v])
        if (!vis[u/2])
            dfs(u);
}

void solve() {
    vis.clear(), add.clear(), a.clear();
    read(n, m);
    for (int i=0; i<n*m*2; ++i)
        adj[i].clear();
    vis.resize(n*m*2), add.resize(n*m*2), a.resize(n, vi(m));
    read(a);
    for (int i=0; i<n; ++i)
        for (int j=0; j<m; ++j) {
            for (int k=0; k<4; ++k) {
                int ni=i+dy[k], nj=j+dx[k];
                if (in(ni, nj)) {
                    int v=i*m+j, u=ni*m+nj;
                    if (a[i][j]+1==a[ni][nj])
                        adj[v*2].eb(u*2);
                    else if (a[i][j]==a[ni][nj]) {
                        adj[v*2+1].eb(u*2);
                        adj[v*2].eb(u*2+1);
                    }
                    else if (a[i][j]-1==a[ni][nj])
                        adj[v*2+1].eb(u*2+1);
                }
            }
        }
    /*
    for (int i=0; i<n*m*2; ++i) {
        print((i&1?"off":"on"), "node of", ((i/2)/m), ((i/2)%m), "implies:");
        //print("adj of", i);
        for (int j:adj[i])
            print((j&1?"off":"on"), "node of", ((j/2)/m), ((j/2)%m));
        print();
    }
    */
    for (int i=0; i<n*m*2; ++i) {
        if (vis[i/2])
            continue;
        dfs(i);
        //print("Now:", (i/2)/m, (i/2)%m);
        //print(a);
    }
    print(a);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

