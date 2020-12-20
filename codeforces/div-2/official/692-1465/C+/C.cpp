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

void solve() {
    int n, m;
    read(n, m);
    vii a(m);
    read(a);
    int ans=INT_MAX;
    { // move horizontally
        map<int, int> mp;
        set<int> taken;
        set<pii> cur;
        for (int i=0; i<m; ++i) {
            mp[a[i].se]=i;
            taken.insert(a[i].fi);
            cur.insert(a[i]);
        }
        int cnt=0;
        queue<int> q;
        for (int i=0; i<m; ++i) {
            if (!taken.count(a[i].se) && (a[i].fi^a[i].se))
                q.push(i);
        }
        while (q.size()) {
            int v=q.front(); q.pop();
            ++cnt;
            cur.erase(a[v]);
            cur.emplace(a[v].se, a[v].se);
            taken.erase(a[v].fi);
            taken.insert(a[v].se);
            if (mp.count(a[v].fi))
                q.push(mp[a[v].fi]);
        }
        int add=0;
        vb vis(m);
        IN(p, cur) {
            if (vis[mp[p.se]] || p.fi==p.se)
                continue;
            //print("we're at ", p);
            int cur=mp[p.se], c=0;
            while (!vis[cur]) {
                ++c;
                //print("cur:", cur);
                vis[cur]=1;
                cur=mp[a[cur].fi];
                //print("nxt:", cur);
            }
            //print(c);
            add+=c+1;
        }
        ckmin(ans, cnt+add);
    }
    { // move vertically
        map<int, int> mp;
        set<int> taken;
        set<pii> cur;
        for (int i=0; i<m; ++i) {
            mp[a[i].fi]=i;
            taken.insert(a[i].se);
            cur.insert(a[i]);
        }
        int cnt=0;
        queue<int> q;
        for (int i=0; i<m; ++i) {
            if (!taken.count(a[i].fi) && (a[i].fi^a[i].se))
                q.push(i);
        }
        while (q.size()) {
            int v=q.front(); q.pop();
            ++cnt;
            cur.erase(a[v]);
            cur.emplace(a[v].fi, a[v].fi);
            taken.erase(a[v].se);
            taken.insert(a[v].fi);
            if (mp.count(a[v].se))
                q.push(mp[a[v].se]);
        }
        int add=0;
        vb vis(m);
        IN(p, cur) {
            if (vis[mp[p.fi]] || p.fi==p.se)
                continue;
            //print("we're at ", p);
            int cur=mp[p.fi], c=0;
            while (!vis[cur]) {
                ++c;
                //print("cur:", cur);
                vis[cur]=1;
                cur=mp[a[cur].se];
                //print("nxt:", cur);
            }
            //print(c);
            add+=c+1;
        }
        ckmin(ans, cnt+add);
    }
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

