//COULD'VE GOTTEN THIS IN CONTEST HAD I DELETED 3 LINES OF CODE
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

pll p[4];

inline ll dist(pll a, pll b) {
    return abs(a.fi-b.fi)+abs(a.se-b.se);
}
inline ll check(pll a, pll b, pll c, pll d) {
    vector<int> perm={0,1,2,3};
    ll ret=INT_MAX;
    do {
        ll cur=0;
        cur+=dist(a, p[perm[0]]);
        cur+=dist(b, p[perm[1]]);
        cur+=dist(c, p[perm[2]]);
        cur+=dist(d, p[perm[3]]);
        ckmin(ret, cur);
    } while (next_permutation(all(perm)));
    return ret;
}
bool cmp(const pll &a, const pll &b) {
    if (a.se==b.se)
        return a.fi<b.fi;
    return a.se<b.se;
}

void solve() {
    vector<ll> xmed, ymed;
    for (int i=0; i<4; ++i)
        cin >> p[i].fi >> p[i].se, xmed.pb(p[i].fi), ymed.pb(p[i].se);
    //for (int i=0; i<4; ++i)
        //for (int j=i+1; j<4; ++j)
            //xmed.pb((p[i].fi+p[j].fi)/2), ymed.pb((p[i].se+p[j].se)/2);
    sort(all(xmed));
    sort(all(ymed));
    ll ans=LLONG_MAX;
    for (int i=0; i<xmed.size(); ++i)
        for (int j=i+1; j<xmed.size(); ++j)
            for (int k=0; k<ymed.size(); ++k) {
                ll cx=xmed[i],
                    cy=ymed[k],
                    dif=xmed[j]-xmed[i];
                ckmin(ans, check(pll(cx, cy), pll(cx+dif, cy), pll(cx, cy+dif), pll(cx+dif, cy+dif)));
                ckmin(ans, check(pll(cx, cy), pll(cx+dif, cy), pll(cx, cy-dif), pll(cx+dif, cy-dif)));
            }
    for (int i=0; i<ymed.size(); ++i)
        for (int j=i+1; j<ymed.size(); ++j)
            for (int k=0; k<xmed.size(); ++k) {
                ll cx=xmed[k],
                    cy=ymed[i],
                    dif=ymed[j]-ymed[i];
                ckmin(ans, check(pll(cx, cy), pll(cx+dif, cy), pll(cx, cy+dif), pll(cx+dif, cy+dif)));
                ckmin(ans, check(pll(cx, cy), pll(cx-dif, cy), pll(cx, cy+dif), pll(cx-dif, cy+dif)));
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


