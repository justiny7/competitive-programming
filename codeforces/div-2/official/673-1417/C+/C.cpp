#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ub upper_bound
#define pqueue priority_queue

#define IN(i, x) for (auto& (i):(x))
#define FIT(i, x) for (auto (i)=(x).begin(); (i)!=(x).end(); ++(i))
#define RIT(i, x) for (auto (i)=(x).rbegin(); (i)!=(x).rend(); ++(i))
#define finish(...) return print(__VA_ARGS__), 0

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

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--) {
        int n; read(n);
        vi a(n); read(a);
        vi ans(n+1, INT_MAX);
        map<int, vi> mp;
        for (int i=0; i<n; ++i)
            mp[a[i]].pb(i);
        for (auto p:mp) {
            vi v=p.se;
            int mx=-1;
            for (int i=1; i<v.size(); ++i)
                ckmax(mx, (v[i]-v[i-1]));
            ckmax(mx, v[0]+1); ckmax(mx, n-v.back());
            if (~mx)
                ckmin(ans[mx], p.fi);
        }
        int c=INT_MAX;
        bool f=0;
        for (int i=1; i<=n; ++i) {
            if (ans[i]^INT_MAX)
                f=1;
            if (f) {
                ckmin(c, ans[i]);
                cout << c << " ";
            }
            else
                cout << "-1 ";
        }
        cout << '\n';
    }
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

