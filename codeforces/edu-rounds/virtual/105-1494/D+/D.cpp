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
template<class T> bool ckmin(T &a, const T b) { return (b < a) ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T b) { return (a < b) ? a = b, 1 : 0; }

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Constants
const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 5e3 + 69;
int n, k, rt, a[N][N], par[N], c[N];

int go(vector<int> v) {
    int sz = v.size(), mx = -1;

    //print("v is", v);

    if (sz == 1)
        return v[0];

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            ckmax(mx, a[v[i]][v[j]]);
            //print(i, j, v[i], v[j], a[v[i]][v[j]]);
        }
    }

    //print("mx is", mx);
    int ret = ++k;
    c[ret] = mx;

    vector<bool> vis(n + 1);
    for (int i = 0; i < sz; ++i) {
        if (vis[v[i]])
            continue;

        vector<int> here;
        for (int j = 0; j < sz; ++j) {
            if (a[v[i]][v[j]] != mx) {
                vis[v[j]] = 1;
                here.push_back(v[j]);
            }
        }

        //print("recursing down with", here);
        par[go(here)] = ret;
    }

    return ret;
}

void solve() {
    read(n), k = n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            read(a[i][j]);
            if (i == j)
                c[i] = a[i][j];
        }
    }

    vector<int> cur(n);
    iota(all(cur), 1);
    rt = go(cur);

    print(k);
    for (int i = 1; i <= k; ++i)
        write(c[i], " \n"[i == k]);
    print(rt);
    for (int i = 1; i <= k; ++i)
        if (i != rt)
            print(i, par[i]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
