#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define IN(i, x) for (auto &(i):(x))
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

template<class T> using pqueue=priority_queue<T>;
template<class T> using mqueue=priority_queue<T, vector<T>, greater<T>>;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<class T> bool ckmin(T &a, const T &b) { return (b<a?a=b, 1:0); }
template<class T> bool ckmax(T &a, const T &b) { return (a<b?a=b, 1:0); }

template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.fi >> p.se; }
template<class T, size_t S> void read(array<T, S> &a) { IN(i, a) read(i); }

template<class T> void read(vector<T> &v) { IN(i, v) read(i); }
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.fi << " " << p.se; return o; }
template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; IN(i, a) o << s << i, s=" "; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }

template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; IN(i, v) o << s << i, s=" "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T>> &v) { string s; IN(i, v) o << s << i, s="\n"; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

const ll M=1e9+7; //998244353;
const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

struct segtree {
    vector<int> t;
    int sz;
    segtree(vector<int> &v) {
        sz=v.size();
        t.resize(sz<<2);
        build(0, sz-1, 1, v);
    }
    void build(int l, int r, int v, vector<int> &a) {
        if (l==r) {
            t[v]=a[l];
            return;
        }
        int m=l+r>>1;
        build(l, m, v<<1, a);
        build(m+1, r, v<<1|1, a);
        t[v]=min(t[v<<1], t[v<<1|1]);
    }
    int query(int l, int r, int lo, int hi, int v) {
        if (l>hi || r<lo)
            return INT_MAX;
        if (lo>=l && hi<=r)
            return t[v];
        int m=lo+hi>>1;
        return min(query(l, r, lo, m, v<<1), query(l, r, m+1, hi, v<<1|1));
    }
    int query(int l, int r) {
        return query(l, r, 0, sz-1, 1);
    }
};

void solve() {
    int n; read(n);
    vi a(n), pref(n), suff(n);
    read(a);
    for (int i=0; i<n; ++i)
        pref[i]=i?max(a[i], pref[i-1]):a[i];
    for (int i=n-1; ~i; --i)
        suff[i]=(i==n-1)?a[i]:max(a[i], suff[i+1]);
    segtree seg(a);
    for (int i=n-1; i>1; --i) {
        int cur=suff[i],
            lo=lb(pref.begin(), pref.begin()+i-1, cur)-pref.begin()+1,
            hi=ub(pref.begin(), pref.begin()+i-1, cur)-pref.begin()+1;
        if (hi<=lo)
            continue;
        while (lo<hi) {
            int m=lo+hi>>1;
            if (seg.query(m, i-1)<cur)
                lo=m+1;
            else
                hi=m;
        }
        if (lo<i && seg.query(lo, i-1)==cur) {
            print("YES");
            print(lo, i-lo, n-i);
            return;
        }
    }
    print("NO");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

