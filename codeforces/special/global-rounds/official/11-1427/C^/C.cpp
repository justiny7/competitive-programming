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

inline int dist(int a, int b, int c, int d) {
    return (abs(a-c)+abs(b-d));
}

void solve() {
    int r, n;
    read(r, n), ++n;
    vector<array<int, 3>> v;
    vi dp(n), dp2(n);
    v.pb({0, 1, 1});
    for (int i=1; i<n; ++i) {
        int a, b, c;
        read(a, b, c);
        v.pb({a, b, c});
    }
    int ans=0;
    for (int i=1; i<n; ++i) {
        int mx=(i-r*2-1>=0?dp2[i-r*2-1]+1:INT_MIN);
        for (int j=max(0, i-r*2); j<i; ++j)
            if (dist(v[i][1], v[i][2], v[j][1], v[j][2])<=v[i][0]-v[j][0])
                ckmax(mx, dp[j]+1);
        dp[i]=mx, dp2[i]=max(dp2[i-1], dp[i]), ckmax(ans, dp2[i]);
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

