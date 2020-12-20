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

//More utilities
template<class T> bool ckmin(T &a, const T &b) { return (b<a?a=b, 1:0); }
template<class T> bool ckmax(T &a, const T &b) { return (a<b?a=b, 1:0); }

//Constants
const ll M=1e9+7; //998244353;
const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const string chars="01?";

void solve() {
    string s; read(s);
    ll x, y; read(x, y);
    int n=s.size();
    map<char, vl> pre, suf;
    pre['0']=pre['1']=pre['?']=vl(n+2);
    suf['0']=suf['1']=suf['?']=vl(n+2);
    for (int i=0; i<n; ++i)
        for (char t:chars)
            pre[t][i+1]=pre[t][i]+(s[i]==t);
    for (int i=n; i; --i)
        for (char t:chars)
            suf[t][i]=suf[t][i+1]+(s[i-1]==t);
    if (!count(all(s), '?')) {
        ll c0=0, c1=0, ans=0;
        for (int i=0; i<n; ++i) {
            if (s[i]=='1')
                ans+=x*c0;
            else if (s[i]=='0')
                ans+=y*c1;
            if (s[i]=='0')
                ++c0;
            else
                ++c1;
        }
        finish(ans);
    }
    ll ans=0, tot=LLONG_MAX;
    string sq="01";
    if (x>y)
        sq="10";
    {
        ll c0=0, c1=0;
        for (int i=0; i<n; ++i) {
            if (s[i]=='1')
                ans+=x*c0;
            else if (s[i]=='0')
                ans+=y*c1;
            else if (s[i]=='?') {
                if (sq[1]=='1')
                    ans+=x*c0;
                else
                    ans+=y*c1;
            }
            if (s[i]=='1')
                ++c1;
            else if (s[i]=='0')
                ++c0;
            else {
                if (sq[1]=='0')
                    ++c0;
                else
                    ++c1;
            }
        }
    }
    ckmin(tot, ans);
    //print(ans);
    for (int i=1; i<=n; ++i) {
        if (s[i-1]^'?')
            continue;
        if (sq[1]=='1') { // we're changing 1 to 0
            ans-=x*(pre['0'][i-1]+pre['?'][i-1]);
            ans-=y*(suf['0'][i+1]);
            ans+=y*(pre['1'][i-1]);
            ans+=x*(suf['1'][i+1]+suf['?'][i+1]);
        }
        else { // we're changing 0 to 1
            ans-=y*(pre['1'][i-1]+pre['?'][i-1]);
            ans-=x*(suf['1'][i+1]);
            ans+=x*(pre['0'][i-1]);
            ans+=y*(suf['0'][i+1]+suf['?'][i+1]);
        }
        //print(ans);
        ckmin(tot, ans);
    }
    print(tot);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

