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
//const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

const int dy[]={1, 1, 0, -1, -1, 0}, dx[]={1, 0, -1, -1, 0, 1};

void solve() {
    ll x, y;
    vl c(6);
    read(x, y, c);
    if (!x && !y)
        finish(0);
    for (int i=0; i<6; ++i) {
        int l=(i+5)%6, r=(i+1)%6;
        ckmin(c[i], c[l]+c[r]);
    }
    for (int i=0; i<6; ++i) {
        ll m=-1;
        if (!x) {
            if (dx[i])
                continue;
        }
        else {
            if (!dx[i] || ((dx[i]<0)^(x<0)) || x%dx[i]>0)
                continue;
            m=x/dx[i];
        }
        if (m<0) {
            if (!y) {
                if (dy[i])
                    continue;
            }
            else {
                if (!dy[i] || ((dy[i]<0)^(y<0)) || y%dy[i]>0)
                    continue;
                m=y/dy[i];
            }
        }
        else
            if (m*dy[i]^y)
                continue;
        finish(c[i]*m);
    }
    int d1, d2;
    if (y>0) {
        if (x<0)
            d1=1, d2=2;
        else {
            if (x<y)
                d1=0, d2=1;
            else
                d1=5, d2=0;
        }
    }
    else {
        if (x>0)
            d1=4, d2=5;
        else {
            if (x<y)
                d1=2, d2=3;
            else
                d1=3, d2=4;
        }
    }
    //print("d1:", d1, "d2:", d2);
    if ((y<0 && x>0) || (x<0 && y>0))
        finish(abs(c[d2]*x)+abs(c[d1]*y));
    ll cx=0, cy=0, ans=0;
    if (!dx[d1] || !dx[d2]) {
        ll m=abs(x);
        if (!dx[d1]) {
            cx+=dx[d2]*m, cy+=dy[d2]*m, ans+=c[d2]*m;
            ans+=c[d1]*max(abs(y-cy), abs(x-cx));
        }
        else {
            cx+=dx[d1]*m, cy+=dy[d1]*m, ans+=c[d1]*m;
            ans+=c[d2]*max(abs(y-cy), abs(x-cx));
        }
    }
    else if (!dy[d1] || !dy[d2]) {
        ll m=abs(y);
        if (!dy[d1]) {
            cx+=dx[d2]*m, cy+=dy[d2]*m, ans+=c[d2]*m;
            ans+=c[d1]*max(abs(y-cy), abs(x-cx));
        }
        else {
            cx+=dx[d1]*m, cy+=dy[d1]*m, ans+=c[d1]*m;
            ans+=c[d2]*max(abs(y-cy), abs(x-cx));
        }
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

