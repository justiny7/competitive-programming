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
#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)

//Loops
#define IN(i, x) for (auto &(i):(x))
#define FIT(i, x) for (auto (i)=(x).begin(); (i)!=(x).end(); ++(i))
#define RIT(i, x) for (auto (i)=(x).rbegin(); (i)!=(x).rend(); ++(i))

//Data types/structures
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

//Debug
#ifdef LOCAL
template<class T> void err(T x) { cerr << x; }
template<class H, class T> void err(pair<H, T> p) { cerr << '{' << p.fi << ", " << p.se << '}'; }
template<class T, size_t S> void err(array<T, S> a) { cerr << '{'; string s; IN(i, a) cerr << s, err(i), s=", "; cerr << '}'; }
template<class T> void err(vector<T> v) { cerr << '{'; string s; IN(i, v) cerr << s, err(i), s=", "; cerr << '}'; }

stringstream ss_err;
void dbg() { err("\n\n"); }
template<class H, class... T> void dbg(const H &h, const T &...t) {
    string s; ss_err >> s;
    if (sizeof...(t))
        s.pop_back();
    cerr << s << " is ", err(h);
    if (sizeof...(t))
        cerr << '\n';
    dbg(t...);
}

#define debug(...) ss_err=stringstream(#__VA_ARGS__); cerr << "\n[Line " << __LINE__ << "]:\n", dbg(__VA_ARGS__)
#define check(...) if (!(__VA_ARGS__)) cerr << "\n[Line " << __LINE__ << "]:\nCheck failed in " << __FUNCTION__ << ": " << #__VA_ARGS__ << "\n\n"

#else
#define debug(...)
#define check(...)

#endif

//More utilities
template<class T> bool ckmin(T &a, const T &b) { return (b<a?a=b, 1:0); }
template<class T> bool ckmax(T &a, const T &b) { return (a<b?a=b, 1:0); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Constants
const ll M=1e9+7; //998244353;
const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int n;
vl a, mx;
ll dfs(int i) {
    if (i>=n)
        return 0;
    if (~mx[i])
        return mx[i];
    mx[i]=max(mx[i], a[i]+dfs(i+a[i]));
    return mx[i];
}

void solve() {
    read(n);
    a.clear(); a.resize(n);
    mx.clear(); mx.resize(n, -1);
    read(a);
    ll ans=0;
    for (int i=0; i<n; ++i)
        mx[i]=dfs(i);
    for (int i=0; i<n; ++i)
        ckmax(ans, mx[i]);
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

