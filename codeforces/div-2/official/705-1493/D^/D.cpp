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

const int mxN=2e5+1;
int n, q;
ll a[mxN];
map<int, multiset<ll>> mp;
map<int, int> fact[mxN], cur[mxN];
vector<int> primes;
bool ok[mxN];

void sieve() {
    memset(ok, 1, sizeof(ok));
    ok[0]=ok[1]=0;
    for (ll i=2; i*i<=mxN; ++i) {
        if (ok[i]) {
            primes.push_back(i);
            for (ll j=i*i; j*j<=mxN; j+=i)
                ok[j]=0;
        }
    }
}
ll binpow(ll a, ll b) {
    ll ret=1;
    while (b) {
        if (b&1)
            (ret*=a)%=M;
        (a*=a)%=M, b>>=1;
    }
    return ret;
}

void solve() {
    read(n, q);
    for (int i=0; i<n; ++i) {
        read(a[i]);
        cur[i]=fact[a[i]];
        IN(p, fact[a[i]])
            mp[p.first].insert(p.second);
    }
    ll ret=1;
    IN(p, mp)
        if (p.second.size()==n)
            (ret*=binpow(p.first, (*p.second.begin())))%=M;
    while (q--) {
        //print("---");
        ll i, x;
        read(i, x), --i;
        for (auto [p, c]:fact[x]) {
            //print('>', p, c);
            ll orig=0;
            if (mp.count(p) && mp[p].size()==n)
                orig=*mp[p].begin();
            if (cur[i].count(p))
                mp[p].erase(mp[p].find(cur[i][p]));
            cur[i][p]+=c;
            mp[p].insert(cur[i][p]);
            if (mp[p].size()<n)
                continue;
            ll en=*mp[p].begin();
            (ret*=binpow(p, (en-orig)))%=M;
        }
        print(ret);
    }
}

int main() {
    sieve();
    for (int i=1; i<mxN; ++i) {
        int x=i;
        IN(p, primes)
            while (x%p==0)
                ++fact[i][p], x/=p;
        if (x>1)
            ++fact[i][x];
    }
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}
 
