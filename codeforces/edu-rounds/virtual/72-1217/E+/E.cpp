#include <bits/stdc++.h>
using namespace std;

// TEMPLATE {{{

/* Macros */
#define all(x) (x).begin(), (x).end()
#define finish(...) return void(print(__VA_ARGS__))

/* Input */
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { for (T &i : a) read(i); }
template<class T> void read(vector<T> &v) { for (T &i : v) read(i); }

template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

/* Output */
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; for (T i : a) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T i : v) o << s << i, s = " "; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

/* Misc */
template<class T> bool ckmin(T &a, const T b) { return (b < a) ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T b) { return (a < b) ? a = b, 1 : 0; }

using ll = long long;

// }}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// unbalanced subset exists if more than one non-zero occurrence of a digit
// smallest subset is a pair

const int N = 2e5 + 69;
int n, m;

// Segtree {{{
struct node {
    ll ans, dig[10];
    node() {
        ans = 1e10;
        fill(dig, dig + 10, 1e10);
    }
} t[N * 4];

node comb(node p, node q) {
    node ret;

    ret.ans = min(p.ans, q.ans);
    for (int i = 0; i < 10; ++i) {
        ckmin(ret.ans, p.dig[i] + q.dig[i]);
        ret.dig[i] = min(p.dig[i], q.dig[i]);
    }

    return ret;
}
void upd(int i, int x, int l = 0, int r = n - 1, int v = 1) {
    //print(i, x, l, r, v);
    if (l == r) {
        t[v] = node();

        string s = to_string(x);
        reverse(all(s));
        for (int j = 0; j < s.size(); ++j)
            if (s[j] > '0')
                t[v].dig[j] = x;
    }
    else {
        int m = l + r >> 1;
        if (i <= m)
            upd(i, x, l, m, v * 2);
        else
            upd(i, x, m + 1, r, v * 2 + 1);

        t[v] = comb(t[v * 2], t[v * 2 + 1]);
    }
}
node query(int ql, int qr, int l = 0, int r = n - 1, int v = 1) {
    if (ql > r || qr < l)
        return node();
    if (l >= ql && r <= qr)
        return t[v];

    int m = l + r >> 1;
    return comb(query(ql, qr, l, m, v * 2), query(ql, qr, m + 1, r, v * 2 + 1));
}
// }}}

void solve() {
    read(n, m);

    for (int i = 0; i < n; ++i) {
        int x; read(x);
        upd(i, x);
    }

    while (m--) {
        int type; read(type);

        if (type & 1) {
            int i, x;
            read(i, x), --i;
            upd(i, x);
        }
        else {
            int l, r;
            read(l, r), --l, --r;

            ll ret = query(l, r).ans;
            print((ret < 1e10) ? ret : -1);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
