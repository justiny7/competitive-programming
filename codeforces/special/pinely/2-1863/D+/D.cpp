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
bool ckmin(auto &a, const auto &b) { return (a > b) ? a = b, 1 : 0; }
bool ckmax(auto &a, const auto &b) { return (a < b) ? a = b, 1 : 0; }

using ll = long long;

// }}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {
    int n, m;
    read(n, m);

    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            read(g[i][j]);

    for (int i = 0; i < n; ++i) {
        int c = 0;
        for (int j = 0; j < m; ++j)
            c += (g[i][j] != '.');

        if (c & 1)
            finish(-1);
    }
    for (int i = 0; i < m; ++i) {
        int c = 0;
        for (int j = 0; j < n; ++j)
            c += (g[j][i] != '.');

        if (c & 1)
            finish(-1);
    }

    for (int i = 0; i < m - 1; ++i) {
        int c = 0;
        for (int j = 0; j < n; ++j) {
            if (g[j][i] == 'L' && g[j][i + 1] == 'R') {
                ++c;
                g[j][i] = (c & 1) ? 'W' : 'B';
                g[j][i + 1] = (c & 1) ? 'B' : 'W';
            }
        }

        if (c & 1)
            finish(-1);
    }
    for (int i = 0; i < n - 1; ++i) {
        int c = 0;
        for (int j = 0; j < m; ++j) {
            if (g[i][j] == 'U' && g[i + 1][j] == 'D') {
                ++c;
                g[i][j] = (c & 1) ? 'W' : 'B';
                g[i + 1][j] = (c & 1) ? 'B' : 'W';
            }
        }

        if (c & 1)
            finish(-1);
    }

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

