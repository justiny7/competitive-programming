#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//{{{ TEMPLATE 

//Macros
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define finish(...) return void(print(__VA_ARGS__))
#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)

#define IN(i, x) for (auto &(i):(x))
#define FIT(i, x) for (auto (i)=(x).begin(); (i)!=(x).end(); ++(i))
#define RIT(i, x) for (auto (i)=(x).rbegin(); (i)!=(x).rend(); ++(i))

//Input
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { IN(i, a) read(i); }

template<class T> void read(vector<T> &v) { IN(i, v) read(i); }
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

//Output
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; IN(i, a) o << s << i, s=" "; return o; }

template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; IN(i, v) o << s << i, s=" "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

//Misc
template<class T> bool ckmin(T &a, const T &b) { return (b<a?a=b, 1:0); }
template<class T> bool ckmax(T &a, const T &b) { return (a<b?a=b, 1:0); }

using ll=long long;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Constants
const ll M=1e9+7; //998244353;
const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int pct(ll x) {
    return __builtin_popcountll(x);
}
bool check(ll b, ll e) {
    assert(pct(b)==pct(e));
    vector<ll> x, y;
    for (ll i=0; i<31; ++i) {
        if (b&(1LL<<i))
            x.push_back(i);
        if (e&(1LL<<i))
            y.push_back(i);
    }
    for (int i=0; i<x.size(); ++i)
        if (x[i]>y[i])
            return 0;
    return 1;
}

void solve() {
    ll b, e;
    read(b, e);
    if (b>e)
        finish("NO");
    if (e==b)
        finish("YES");
    if (b%2==0 && e%2==1)
        finish("NO");
    if (pct(e)>pct(b))
        finish("NO");
    ll dd=e-b;
    if (dd&b==dd)
        finish("YES");
    if (pct(e)==pct(b)) {
        //print("HERE");
        if (check(b, e))
            finish("YES");
        else
            finish("NO");
    }
    //pct(e) < pct(b)
    ll ecnt=pct(e), bcnt=pct(b), dif=bcnt-ecnt;
    assert(dif>0);
    vector<ll> x, y;
    for (int i=0; i<31; ++i)
        if (b&(1LL<<i))
            x.push_back(i);
    //merge last dif bits of b
    int n=bcnt, ind=dif, lst=x[ind++]+1;
    while (ind<bcnt && lst==x[ind])
        lst=x[ind++]+1;
    ll ret=0;
    if (ind==bcnt) {
        for (int i=0; i<ecnt; ++i)
            ret|=(1LL<<(lst-i));
    }
    else {
        for (int i=ind; i<bcnt; ++i, --ecnt)
            ret|=(1LL<<x[i]);
        for (int i=0; ecnt>0; ++i, --ecnt)
            ret|=(1LL<<(lst-i));
    }
    if (ret>e || !check(ret, e))
        finish("NO");
    print("YES");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

