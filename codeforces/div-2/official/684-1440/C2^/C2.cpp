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

vector<array<int, 6>> ans;
void go(int x1, int y1, int x2, int y2, int x3, int y3, vector<vi> &a) {
    a[x1][y1]^=1;
    a[x2][y2]^=1;
    a[x3][y3]^=1;
    ans.pb({x1+1, y1+1, x2+1, y2+1, x3+1, y3+1});
}

void solve() {
    ans.clear();
    int n, m;
    read(n, m);
    vector<vi> a(n, vi(m));
    for (int i=0; i<n; ++i) {
        string s; read(s);
        for (int j=0; j<m; ++j)
            a[i][j]=(s[j]-'0');
    }
    if (n&1) {
        for (int i=0; i<m-1; ++i)
            if (a[n-1][i])
                go(n-1, i, n-2, i, n-2, i+1, a);
        if (a[n-1][m-1])
            go(n-1, m-1, n-2, m-1, n-2, m-2, a);
    }
    if (m&1) {
        if (a[0][m-1])
            go(0, m-1, 0, m-2, 1, m-2, a);
        for (int i=1; i<n-1; ++i)
            if (a[i][m-1])
                go(i, m-1, i, m-2, i-1, m-2, a);
        if (a[n-1][m-1])
            go(n-1, m-1, n-1, m-2, n-2, m-2, a);
    }
    for (int i=0; i<n-1; i+=2)
        for (int j=0; j<m-1; j+=2) {
            int c=a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];
            if (c==4)
                go(i, j, i+1, j, i, j+1, a), c=1;
            if (c==1) {
                if (!a[i][j])
                    go(i, j+1, i+1, j, i+1, j+1, a);
                else
                    go(i, j, i+1, j, i, j+1, a);
                c=2;
            }
            if (c==2) {
                if (a[i][j])
                    go(i+1, j, i, j+1, i+1, j+1, a);
                else if (a[i][j+1])
                    go(i+1, j, i, j, i+1, j+1, a);
                else if (a[i+1][j])
                    go(i, j, i, j+1, i+1, j+1, a);
                else
                    go(i+1, j, i, j+1, i, j, a);
                c=3;
            }
            if (c==3) {
                if (!a[i][j])
                    go(i+1, j, i, j+1, i+1, j+1, a);
                else if (!a[i][j+1])
                    go(i+1, j, i, j, i+1, j+1, a);
                else if (!a[i+1][j])
                    go(i, j, i, j+1, i+1, j+1, a);
                else
                    go(i+1, j, i, j+1, i, j, a);
            }
            //print(a);
            //print();
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

