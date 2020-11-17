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

array<int, 6> op[4]={
    {1, 0, 1, 1, 0, 1},
    {0, 0, 1, 1, 1, 0},
    {0, 0, 1, 1, 0, 1},
    {0, 0, 1, 0, 0, 1}
};

vector<array<int, 6>> go(int x) {
    int pct=__builtin_popcount(x);
    vector<array<int, 6>> ret;
    if (pct==0)
        return ret;
    if (pct==3) {
        for (int i=0; i<4; ++i)
            if (!(x&(1<<i))) {
                if (i==0)
                    ret.pb(op[0]);
                else if (i==1)
                    ret.pb(op[1]);
                else if (i==2)
                    ret.pb(op[2]);
                else
                    ret.pb(op[3]);
                break;
            }
        return ret;
    }
    else if (pct==2) {
        int c1=-1, c2;
        for (int i=0; i<4; ++i)
            if (x&(1<<i))
                c1<0?c1=i:c2=i;
        if (c1==0) {
            if (c2==1)
                ret.pb(op[1]);
            else if (c2==2)
                ret.pb(op[2]);
            else
                ret.pb(op[3]);
            ret.pb(op[0]);
        }
        else if (c1==1) {
            if (c2==2)
                ret.pb(op[2]);
            else
                ret.pb(op[3]);
            ret.pb(op[1]);
        }
        else {
            ret.pb(op[3]);
            ret.pb(op[2]);
        }
        return ret;
    }
    else if (pct==1) {
        for (int i=0; i<4; ++i)
            if (x&(1<<i)) {
                if (i==0) {
                    ret.pb(op[3]);
                    ret.pb(op[1]);
                    ret.pb(op[2]);
                }
                else if (i==1) {
                    ret.pb(op[2]);
                    ret.pb(op[0]);
                    ret.pb(op[3]);
                }
                else if (i==2) {
                    ret.pb(op[1]);
                    ret.pb(op[0]);
                    ret.pb(op[3]);
                }
                else {
                    ret.pb(op[0]);
                    ret.pb(op[1]);
                    ret.pb(op[2]);
                }
                return ret;
            }
    }
    ret.pb(op[0]);
    ret.pb(op[3]);
    ret.pb(op[1]);
    ret.pb(op[2]);
    return ret;
}
vector<array<int, 6>> get_ans(vector<vi> &a, int msk, int i, int j) {
    vector<array<int, 6>> ret=go(msk);
    for (int t=0; t<ret.size(); ++t)
        for (int y=0; y<6; y+=2) {
            ret[t][y]+=i+1, ret[t][y+1]+=j+1;
            a[ret[t][y]-1][ret[t][y+1]-1]^=1;
        }
    return ret;
}

void solve() {
    int n, m;
    read(n, m);
    vector<vi> a(n, vi(m));
    for (int i=0; i<n; ++i) {
        string s; read(s);
        for (int j=0; j<m; ++j)
            a[i][j]=(s[j]-'0');
    }
    vector<array<int, 6>> ans;
    for (int i=0; i<n-1; ++i)
        for (int j=0; j<m-1; ++j) {
            int x=0;
            x|=(a[i][j]);
            x|=(a[i][j+1]<<1);
            x|=(a[i+1][j]<<2);
            x|=(a[i+1][j+1]<<3);
            vector<array<int, 6>> cur=get_ans(a, x, i, j);
            for (auto v:cur)
                ans.pb(v);
        }
    print(ans.size());
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0*clock()/CLOCKS_PER_SEC << "s\n";
}

