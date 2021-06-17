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

int go(vector<int> &a, vector<int> &b) {
    int n = a.size(), m = b.size(), ret = 0;

    set<int> s;
    for (int i : a)
        s.insert(i);

    vector<int> ok(m + 1);
    for (int i = m - 1; ~i; --i) {
        if (s.count(b[i]))
            ok[i] = 1;
        ok[i] += ok[i + 1];
    }

    int l = 0, r = 0, len = 0, idx = 0;
    while (l < m) {
        while (idx < n && a[idx] <= b[l] + len)
            ++idx, ++len;
        while (r < m && b[l] + len > b[r])
            ++r;

        //print(l, r, idx, r - l + ok[r]);

        ckmax(ret, r - l + ok[r]);
        ++l;
    }

    //print(">>>");
    //print("A:", a);
    //print("B:", b);
    //print("RET:", ret);

    return ret;
}

void solve() {
    int n, m;
    read(n, m);

    vector<int> apos, aneg, bpos, bneg;
    for (int i = 0; i < n; ++i) {
        int x; read(x);
        if (x > 0)
            apos.push_back(x);
        else
            aneg.push_back(-x);
    }
    for (int i = 0; i < m; ++i) {
        int x; read(x);
        if (x > 0)
            bpos.push_back(x);
        else
            bneg.push_back(-x);
    }

    reverse(all(aneg)); reverse(all(bneg));
    print(go(apos, bpos) + go(aneg, bneg));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
