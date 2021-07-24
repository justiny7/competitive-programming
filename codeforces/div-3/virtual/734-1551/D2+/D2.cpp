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

void solve() {
    int n, m, k;
    read(n, m, k);

    if (m == 2) {
        if ((k & 1) != (n & 1))
            finish("NO");

        print("YES");
        for (int i = 0; i < k; ++i)
            print((i & 1) ? "aa" : "bb");
        for (int i = 0; i < (n - k) / 2; ++i) {
            print((i & 1) ? "zy" : "yz");
            print((i & 1) ? "zy" : "yz");
        }
        return;
    }

    // after each horizontal placement, free spots in each col must be even
    vector<vector<char>> g(n, vector<char>(m, '?'));

    // odd rows --> fill first row with horizontal
    if (n & 1) {
        if (k < m / 2)
            finish("NO");

        assert(m % 2 == 0);
        for (int i = 0; i < m / 2; ++i)
            g[0][i * 2] = g[0][i * 2 + 1] = char('a' + (i & 1));

        k -= m / 2;
    }

    if (k & 1)
        finish("NO");

    for (int i = 0; i < m / 2; ++i) {
        for (int j = (n & 1); j < n; ++j) {
            if (!k)
                break;

            --k;
            g[j][i * 2] = g[j][i * 2 + 1] = char('a' + ((j & 1) ^ (i & 1)));
        }

        if (!k)
            break;
    }

    if (k)
        finish("NO");

    int add = (n & 1);
    for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < m; ++j) {
            if (g[i * 2 + add][j] == '?')
                g[i * 2 + add][j] = g[i * 2 + add + 1][j] = char('y' + ((j & 1) ^ ((i + add) & 1)));
        }
    }

    print("YES");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j)
            write(g[i][j]);
        print();
    }
}
int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
