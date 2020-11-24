#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define IN(i, x) for (auto &(i):(x))
#define FIT(i, x) for (auto (i)=(x).begin(); (i)!=(x).end(); ++(i))
#define RIT(i, x) for (auto (i)=(x).rbegin(); (i)!=(x).rend(); ++(i))
#define finish(...) return void(print(__VA_ARGS__))

using ll=long long;
using db=double;
using ld=long double;

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

template<class T> using pqueue=priority_queue<T>;
template<class T> using mqueue=priority_queue<T, vector<T>, greater<T>>;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T &a, const T &b) { return (b<a?a=b, 1:0); }
template<class T> bool ckmax(T &a, const T &b) { return (a<b?a=b, 1:0); }

template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.fi >> p.se; }
template<class T, size_t S> void read(array<T, S> &a) { IN(i, a) read(i); }

template<class T> void read(vector<T> &v) { IN(i, v) read(i); }
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.fi << " " << p.se; return o; }
template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; IN(i, a) o << s << i, s=" "; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }

template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; IN(i, v) o << s << i, s=" "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

const ll M=1e9+7; //998244353;
const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

int n;
vector<vi> adj;
vi vis, par, treesz;
set<int> cycle;

void dfs(int v=1, int p=0) {
    par[v]=p, vis[v]=1;
    IN(u, adj[v]) {
        if (u==p)
            continue;
        if (!vis[u])
            dfs(u, v);
        else if (vis[u]==1) {
            int cur=v;
            while (cur^u)
                cycle.insert(cur), cur=par[cur];
            cycle.insert(u);
        }
    }
    vis[v]=2;
}
void dfs2(int v) {
    ++treesz.back(), vis[v]=1;
    IN(u, adj[v])
        if (!vis[u] && !cycle.count(u))
            dfs2(u);
}

void solve() {
    adj.clear();
    cycle.clear();
    treesz.clear();
    vis.clear();
    par.clear();
    read(n);
    adj.resize(n+1);
    vis.resize(n+1, 0);
    par.resize(n+1, -1);
    for (int i=0; i<n; ++i) {
        int a, b;
        read(a, b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs();
    fill(all(vis), 0);
    IN(v, cycle)
        treesz.pb(0), dfs2(v), --treesz.back();
    //IN(i, cycle)
        //write(i, ' ');
    //print();
    //print(treesz);
    ll sz=cycle.size(), ans=sz*(sz-1), cnt=0;
    IN(i, treesz) {
        if (!i)
            continue;
        ans+=2LL*(sz+cnt-1)*(ll)i;
        ans+=(ll)i*(ll)(i+1)/2;
        cnt+=i;
    }
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

