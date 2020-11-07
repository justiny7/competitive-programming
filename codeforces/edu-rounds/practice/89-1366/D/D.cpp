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
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue

//Some for loop stuff stolen from tmw's template
#define for_base(i, a, b, x) for (int i=(a); ((a)<(b))?i<(b):i>(b); ((a)<(b))?i+=(x):i-=(x))
#define FOR1(a) for_base(i, 0, a, 1)
#define FOR2(i, a) for_base(i, 0, a, 1)
#define FOR3(i, a, b) for_base(i, a, b, 1)
#define FOR4(i, a, b, x) for_base(i, a, b, x)
#define FIFTH(a, b, c, d, e, ...) e
#define FOR(...) FIFTH(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)
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
template<class H, class... T> void read(H& h, T&... t) {
    read(h);
    read(t...);
}

string to_string(char c) {
    return string(1, c);
}
string to_string(string s) {
    return s;
}
string to_string(const char* s) {
    return string(s);
}
string to_string(bool b) {
    return b?"1":"0";
}
template<class T> string to_string(vector<T>& v) {
    string ans="";
    bool f=0;
    in(i, v) {
        if (f)
            ans.pb(' ');
        f=1;
        ans.append(to_string(i));
    }
    return ans;
}
template<class H, class T> string to_string(vector<pair<H, T>>& v) {
    string ans="";
    bool f=0;
    in(p, v) {
        if (f)
            ans.pb('\n');
        ans.append(to_string(p.fi)+' '+to_string(p.se));
        f=1;
    }
    return ans;
}

template<class T> void write(T x) {
    cout << to_string(x);
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

const ll MOD=1e9+7;
const ll MOD2=998244353;
const int kx[]={0,1,0,-1}, ky[]={1,0,-1,0};

void fileIO(string filename) {
    freopen((filename+".in").c_str(), "r", stdin);
    freopen((filename+".out").c_str(), "w", stdout);
}

const int mxA=1e7+1;
int n, spf[mxA];
bool is_prime[mxA];

void sieve() {
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0]=is_prime[1]=0;
    for (int i=2; i*i<mxA; ++i)
        if (is_prime[i])
            for (int j=i*i; j<mxA; j+=i) {
                is_prime[j]=0;
                spf[j]=i;
            }
}

ll div(ll x) {
    if (is_prime[x])
        return 1;
    ll ans=x;
    for (; ans%spf[x]==0; ans/=spf[x]);
    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();
    //fileIO("");
    read(n);
    vl a, b;
    while (n--) {
        ll i, j; read(i);
        j=div(i);
        if (j>1)
            a.pb(spf[i]), b.pb(j);
        else
            a.pb(-1), b.pb(-1);
    }
    in(i, a) cout << i << " ";
    cout << '\n';
    in(i, b) cout << i << " ";
    cout << '\n';
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}


