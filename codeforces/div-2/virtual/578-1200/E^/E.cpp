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

using pi=pair<int, int>;
using pl=pair<ll, ll>;
using pd=pair<db, db>;

using vi=vector<int>;
using vl=vector<ll>;
using vd=vector<db>;
using vb=vector<bool>;
using vs=vector<string>;

using vpi=vector<pi>;
using vpl=vector<pl>;
using vpd=vector<pd>;

using vvi=vector<vi>;
using vvl=vector<vl>;
using vvb=vector<vb>;

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


const int mxN=1e6+1;
const ll M1=1e9+7, M2=1e9+9, B=uid(501, M-2);
ll p1[mxN], p2[mxN], inv1[mxN], inv2[mxN];

ll binpow(ll a, ll b, ll MOD) {
    ll ret=1;
    while (b) {
        if (b&1)
            (ret*=a)%=MOD;
        (a*=a)%=MOD, b>>=1;
    }
    return ret;
}

struct Hash {
    vl hsh1, hsh2;
    Hash(string s) {
        int sz=s.size();
        hsh1.resize(sz+1), hsh2.resize(sz+1);
        for (int i=0; i<sz; ++i) {
            hsh1[i+1]=(hsh1[i]+s[i]*p1[i])%M1;
            hsh2[i+1]=(hsh2[i]+s[i]*p2[i])%M2;
        }
    }
    pl get(int st, int len) {
        int en=st+len;
        ll ret1=(((hsh1[en]-hsh1[st])*inv1[st]%M1)+M1)%M1,
           ret2=(((hsh2[en]-hsh2[st])*inv2[st]%M2)+M2)%M2;
        return pl(ret1, ret2);
    }
};

void solve() {
    int n; read(n);
    string ans;
    while (n--) {
        string s; read(s);
        int sz=min(s.size(), ans.size()), st=0;
        if (!sz) {
            for (int i=0; i<s.size(); ++i)
                ans+=s[i];
            continue;
        }
        Hash h1(ans.substr(ans.size()-sz)), h2(s.substr(0, sz));
        for (int i=sz; i; --i) {
            if (h1.get(sz-i, i)==h2.get(0, i)) {
                st=i;
                break;
            }
        }
        for (int i=st; i<s.size(); ++i)
            ans+=s[i];
    }
    print(ans);
}

int main() {
    p1[0]=p2[0]=inv1[0]=inv2[0]=1;
    for (int i=1; i<mxN; ++i) {
        p1[i]=p1[i-1]*B%M1;
        p2[i]=p2[i-1]*B%M2;
        inv1[i]=binpow(p1[i], M1-2, M1);
        inv2[i]=binpow(p2[i], M2-2, M2);
    }
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

