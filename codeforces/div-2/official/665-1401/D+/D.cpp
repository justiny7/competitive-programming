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
#define mp make_pair
#define beg(x) x.begin()
#define en(x) x.end()
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue

//Some for loop stuff stolen from tmw's template
#define for_base(i, a, b, x) for (int i=((a)<(b))?(a):(a)-1; ((a)<(b))?i<(b):i>=(b); ((a)<(b))?i+=(x):i-=(x))
#define FOR1(a) for_base(i, 0, a, 1)
#define FOR2(i, a) for_base(i, 0, a, 1)
#define FOR3(i, a, b) for_base(i, a, b, 1)
#define FOR4(i, a, b, x) for_base(i, a, b, x)
#define FIFTH(a, b, c, d, e, ...) e
#define FOR(...) FIFTH(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
#define in(i, x) for (auto& i : x)
#define FIT(i, x) for (auto i=(x).begin(); i!=(x).end(); ++i)
#define RIT(i, x) for (auto i=(x).rbegin(); i!=(x).rend(); ++i)
#define finish(x) return print(x), 0

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

template<class T> using min_heap=pqueue<T, vector<T>, greater<T>>;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T& a, const T& b) {return (b<a)?a=b, 1:0;}
template<class T> bool ckmax(T& a, const T& b) {return (a<b)?a=b, 1:0;}

//Read/write stuff also partially stolen from tmw
template<class T> void read(T& x) {
    cin >> x;
}
template<class H, class T> void read(pair<H, T>& p) {
    cin >> p.fi >> p.se;
}
template<class T> void read(vector<T>& v) {
    in(i, v)
        read(i);
}
template<class T> void read(T a[], int n) {
    FOR(n)
        read(a[i]);
}
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}

template<class H, class T> ostream& operator<<(ostream& o, const pair<H, T> &p) {
    o << p.fi << " " << p.se;
    return o;
}
template<class T> ostream& operator<<(ostream& o, vector<T> &v) {
    bool f=0;
    in(i, v) {
        if (f)
            o << " ";
        f=1;
        o << i;
    }
    return o;
}
template<class T> ostream& operator<<(ostream& o, vector<vector<T>> &v) {
    bool f=0;
    in(i, v) {
        if (f)
            o << '\n';
        f=1;
        o << i;
    }
    return o;
}
template<class H, class T> ostream& operator<<(ostream& o, vector<pair<H, T>> &v) {
    bool f=0;
    in(i, v) {
        if (f)
            o << '\n';
        f=1;
        o << i;
    }
    return o;
}

template<class T> void write(T x) {
    cout << x;
}
template<class H, class... T> void write(const H& h, const T&... t) {
    write(h);
    write(t...);
}

void print() {
    write('\n');
}
template<class H, class... T> void print(const H& h, const T&... t) {
    write(h);
    if (sizeof...(t))
        write(' ');
    print(t...);
}

const ll M=1e9+7, M2=998244353;
const int kx[]={0,1,0,-1}, ky[]={1,0,-1,0};

int n;
vector<vi> adj;
vector<vll> adj2;
ll tot;
vl cnt;
vector<pair<ll, pii>> edges;

void dfs(int v=1, int p=0) {
    cnt[v]=1;
    for (int u:adj[v])
        if (u^p) {
            dfs(u, v);
            cnt[v]+=cnt[u];
            edges.pb({cnt[u]*(n-cnt[u]), {v, u}});
        }
}

void dfs2(int v=1, int p=0) {
    for (auto& u:adj2[v])
        if (u.fi^p) {
            tot=(tot+((cnt[u.fi]*(n-cnt[u.fi])%M)*u.se)%M)%M;
            dfs2(u.fi, v);
        }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--) {
        adj.clear(); adj2.clear(); cnt.clear(); edges.clear();
        read(n);
        adj.resize(n+1); adj2.resize(n+1); cnt.resize(n+1);
        tot=0;
        FOR(i, 1, n) {
            int a, b;
            read(a, b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        int m; read(m);
        vl tmp(m); read(tmp);
        sort(all(tmp), greater<ll>());
        vl p;
        if (m<=n-1)
            p=tmp;
        else {
            //print(tmp);
            ll c=1;
            FOR(m-n+2)
                c=c*tmp[i]%M;
            p.pb(c);
            FOR(i, m-n+2, m)
                p.pb(tmp[i]);
        }
        reverse(all(p));
        //print(p);
        dfs();
        sort(all(edges));
        reverse(all(edges));
        assert(edges.size()==n-1);
        in(i, edges) {
            if (p.size()) {
                adj2[i.se.fi].pb({i.se.se, p.back()});
                adj2[i.se.se].pb({i.se.fi, p.back()});
                p.pop_back();
            }
            else {
                adj2[i.se.fi].pb({i.se.se, 1});
                adj2[i.se.se].pb({i.se.fi, 1});
            }
        }
        dfs2();
        print(tot);
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

