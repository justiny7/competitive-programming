#include <bits/stdc++.h>
using namespace std;

//TEMPLATE {{{

//Macros
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define finish(...) return void(print(__VA_ARGS__))
#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)

//Input
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { for (T &i : a) read(i); }

template<class T> void read(vector<T> &v) { for (T &i : v) read(i); }
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

//Output
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; for (T i : a) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T i : v) o << s << i, s = " "; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

//Misc
template<class T> bool ckmin(T &a, const T b) { return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T &a, const T b) { return (a < b ? a = b, 1 : 0); }

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Constants
const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//ST {{{
template<class T> struct ST {
    const T ID = {LLONG_MIN, LLONG_MIN};
    inline T comb(T a, T b) {
        return max(a, b);
    }
    inline void app(T &v, T x) {
        v = x;
    }

    vector<T> t;
    int sz;
    ST() {}
    ST(int SZ): sz(SZ) {
        t.resize(sz << 1, ID);
    }
    ST(vector<T> &v) {
        init(v);
    }
    void init(vector<T> &v) {
        sz = v.size();
        t.resize(sz << 1);
        for (int i = 0; i < sz; ++i)
            t[i + sz] = v[i];
        for (int i = sz - 1; i; --i)
            t[i] = comb(t[i << 1], t[i << 1 | 1]);
    }
    void upd(int i, T x) {
        for (app(t[i += sz], x); i > 1; i >>= 1)
            t[i >> 1] = comb(t[i], t[i ^ 1]);
    }
    T query(int l, int r) {
        T ret = ID;
        for (l += sz, r += sz + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ret = comb(ret, t[l++]);
            if (r & 1)
                ret = comb(ret, t[--r]);
        }
        return ret;
    }
};
//}}}

const int N = 3e5 + 69;
int n; ll ans, c, a[N], d[N], pref[N], suff[N];
ST<pair<ll, ll>> st_d(N), st_p(N), st_s(N);

void go(int l = 1, int r = n) {
    if (l < 1 || l >= r)
        return;
    int m = st_d.query(l + 1, r).second;
    go(l, m - 1); go(m, r);
    ll rt = st_p.query(m, r).first - pref[m - 1];
    ll lf = st_s.query(l, m - 1).first - suff[m];
    ckmax(ans, rt + lf - (d[m] - d[m - 1]) * (d[m] - d[m - 1]));
}

void solve() {
    read(n, c);
    for (int i = 1; i <= n; ++i) {
        read(d[i], a[i]);
        a[i] = c - a[i];
        ckmax(ans, a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
        suff[n - i + 1] = suff[n - i + 2] + a[n - i + 1];
        st_p.upd(i, {pref[i], 0});
        st_s.upd(n - i + 1, {suff[n - i + 1], 0});
    }
    for (int i = 2; i <= n; ++i)
        st_d.upd(i, {d[i] - d[i - 1], i});
    go();
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
    solve();
}
