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

const int N = 2e5 + 69;
int n, m, pref[N], suff[N];
string s, t;

bool ok(int x) {
    for (int i = 0; i + x <= n; ++i) {
        int lf = (i > 0) ? pref[i - 1] : 0,
            rt = (i + x < n) ? suff[i + x] : 0;

        //print(x, i, lf, rt);
        if (lf + rt >= m)
            return 1;
    }

    return 0;
}

void solve() {
    read(s, t);

    n = s.size(), m = t.size();
    for (int i = 0, j = 0; i < n; ++i) {
        if (j < m && s[i] == t[j]) {
            ++pref[i];
            ++j;
        }
        if (i > 0)
            pref[i] += pref[i - 1];
    }
    for (int i = n - 1, j = m - 1; ~i; --i) {
        if (j >= 0 && s[i] == t[j]) {
            ++suff[i];
            --j;
        }
        if (i < n - 1)
            suff[i] += suff[i + 1];
    }

    //for (int i = 0; i < n; ++i)
    //print(i, pref[i], suff[i]);

    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + hi + 1 >> 1;
        if (ok(mid))
            lo = mid;
        else
            hi = mid - 1;
    }

    print(lo);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
