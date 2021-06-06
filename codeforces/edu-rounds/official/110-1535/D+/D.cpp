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

const int K = 20, N = (1 << K);
int n, k, gmp[N], cur;
string s;
pair<int, int> bounds[N];
ll t[N], op[N];
map<char, int> mp;

ll comb(int v) {
    if (op[v] == 0)
        return t[v * 2 + 1];
    else if (op[v] == 1)
        return t[v * 2];
    return t[v * 2] + t[v * 2 + 1];
}
void build(int l = 0, int r = (1 << k - 1) - 1, int v = 1) {
    //print(l, r, v);
    //op[v] = mp[s[cur]];
    bounds[v] = {l, r};
    if (l == r) {
        if (op[v] < 2)
            t[v] = 1;
        else
            t[v] = 2;
        return;
    }
    int m = l + r + 1 >> 1;
    build(l, m - 1, v * 2 + 1);
    build(m, r, v * 2);
    t[v] = comb(v);
}
void upd(int ql, int qr, int x, int l = 0, int r = (1 << k - 1) - 1, int v = 1) {
    if (ql > r || qr < l)
        return;
    //print(ql, qr, x, l, r, v);
    if (ql == l && qr == r) {
        op[v] = x;
        if (l != r)
            t[v] = comb(v);
        else {
            if (x < 2)
                t[v] = 1;
            else
                t[v] = 2;
        }
        //print(">", v, op[v], t[v]);
        return;
    }
    int m = l + r + 1 >> 1;
    upd(ql, qr, x, l, m - 1, v * 2 + 1);
    upd(ql, qr, x, m, r, v * 2);
    t[v] = comb(v);
    //print(">", v, op[v], t[v]);
}

void solve() {
    read(k);
    n = (1 << k) - 1, cur = n;
    read(s);
    op[1] = mp[s.back()];
    gmp[cur--] = 1;
    for (int i = 1; i < k; ++i) {
        for (int j = (1 << i); j < (1 << i + 1); ++j) {
            //print(i, j);
            gmp[cur] = j;
            op[j] = mp[s[--cur]];
            //print("!", j, op[j]);
        }
    }
    //for (int i = 1; i <= n; ++i)
    //print(i, t[i], op[i], gmp[i]);
    build();
    int q; read(q);
    ///*
    while (q--) {
        int x; char c;
        read(x, c);
        auto [l, r] = bounds[gmp[x]];
        //print("updating", l, r, mp[c]);
        upd(l, r, mp[c]);
        print(t[1]);
    }
    //*/
}

int main() {
    mp['0'] = 0, mp['1'] = 1, mp['?'] = 2;
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
    solve();
}
