#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue

#define IN(i, x) for (auto& (i):(x))
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

template<class T> using mqueue=pqueue<T, vector<T>, greater<T>>;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T& a, const T& b) { return (b<a?a=b, 1:0); }
template<class T> bool ckmax(T& a, const T& b) { return (a<b?a=b, 1:0); }

template<class T> void read(T& x) { cin >> x; }
template<class H, class T> void read(pair<H, T>& p) { cin >> p.fi >> p.se; }
template<class T> void read(vector<T>& v) { IN(i, v) read(i); }
template<class H, class... T> void read(H& h, T&... t) { read(h); read(t...); }

template<class H, class T> ostream& operator<<(ostream& o, const pair<H, T> &p) { o << p.fi << " " << p.se; return o; }
template<class H, class T> ostream& operator<<(ostream& o, vector<pair<H, T>> &v) { bool f=0; IN(i, v) o << (f?"\n":"") << i, f=1; return o; }
template<class T> ostream& operator<<(ostream& o, vector<T> &v) { bool f=0; IN(i, v) o << (f?" ":"") << i, f=1; return o; }
template<class T> ostream& operator<<(ostream& o, vector<vector<T>> &v) { bool f=0; IN(i, v) o << (f?"\n":"") << i, f=1; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H& h, const T&... t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H& h, const T&... t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

const ll M=1e9+7; //998244353;
const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

const ll mxN=2e5+5;
ll bit[mxN];

void upd(int i) {
    for (++i; i<mxN; i+=i&-i)
        ++bit[i];
}
ll query(int i) {
    int ans=0;
    for (++i; i; i-=i&-i)
        ans+=bit[i];
    return ans;
}

void solve() {
    int n; string s;
    read(n, s);
    string t=s;
    reverse(all(t));
    map<char, set<int>> mp;
    for (int i=0; i<n; ++i)
        mp[s[i]].insert(i);
    vi a;
    for (int i=0; i<n; ++i) {
        a.pb(*mp[t[i]].begin());
        mp[t[i]].erase(mp[t[i]].begin());
    }
    //print(a);
    ll ans=0;
    for (int i=n-1; ~i; --i) {
        ans+=query(a[i]-1);
        upd(a[i]);
    }
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

