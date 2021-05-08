#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T>> &v) { string s; for (T i : v) o << s << i, s = "\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S>> &v) { string s; for (T i : v) o << s << i, s = "\n"; return o; }

template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T i : v) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T>> &v) { string s; for (T i : v) o << s << i, s = "\n"; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

//Misc
template<class T> bool ckmin(T &a, const T b) { return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T &a, const T b) { return (a < b ? a = b, 1 : 0); }

using ll = long long;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Constants
//const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 69, M = 2e4 + 69;
int n, m, k;
ll dp[N][M], a[N][M], pref[N][M];

ll t[M * 4];
void upd(int i, ll x, int l = 0, int r = m + 10, int v = 1) {
    if (l == r) {
        t[v] = x;
        return;
    }
    int m = l + r >> 1;
    if (i <= m)
        upd(i, x, l, m, v << 1);
    else
        upd(i, x, m + 1, r, v << 1 | 1);
    t[v] = max(t[v << 1], t[v << 1 | 1]);
}
ll query(int ql, int qr, int l = 0, int r = m + 10, int v = 1) {
    if (ql > r || qr < l)
        return 0;
    if (l >= ql && r <= qr)
        return t[v];
    int m = l + r >> 1;
    return max(query(ql, qr, l, m, v << 1), query(ql, qr, m + 1, r, v << 1 | 1));
}

void solve() {
    read(n, m, k);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            read(a[i][j]);
            pref[i][j] = a[i][j] + pref[i][j - 1];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j + k <= m + 1; ++j) { //place rectangle with top left corner (i, j)
            ll here = pref[i][j + k - 1] - pref[i][j - 1], ret = 0;
            if (i < n)
                here += pref[i + 1][j + k - 1] - pref[i + 1][j - 1];
            ll lmax = 0, rmax = 0;
            if (j - k >= 1)
                lmax = query(1, j - k);
            if (j + k <= m)
                rmax = query(j + k, m);
            //print(">", i, j, here, lmax, rmax);
            ret = here + max(lmax, rmax);
            for (int l = max(1, j - k + 1); l <= min(m, j + k - 1); ++l) { //intersecting area?
                ll isect = 0;
                if (l <= j)
                    isect = pref[i][min(l + k - 1, m)] - pref[i][max(0, j - 1)];
                else
                    isect = pref[i][min(j + k - 1, m)] - pref[i][max(l - 1, 0)];
                //print("!", i, j, l, isect);
                ckmax(ret, dp[i - 1][l] + here - isect);
            }
            dp[i][j] = ret;
        }
        for (int j = 1; j + k <= m + 1; ++j) {
            //print("?", i, j, dp[i][j]);
            upd(j, dp[i][j]);
        }
    }
    print(query(1, m));
}

int main() {
    //cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
    solve();
}
