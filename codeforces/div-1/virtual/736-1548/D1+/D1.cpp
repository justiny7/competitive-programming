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

// even coords --> area is even
// how many triangles with even (boundary pts) / 2

const int N = 6e3 + 69;
int n, x[N], y[N];
ll cnt[4][4];

int get(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2)
        return 0;
    return 2;
}

void solve() {
    read(n);

    for (int i = 0; i < n; ++i) {
        read(x[i], y[i]);
        ++cnt[x[i] % 4][y[i] % 4];
    }

    vector<array<int, 2>> mods = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};

    ll ans = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) {
                auto [x1, y1] = mods[i];
                auto [x2, y2] = mods[j];
                auto [x3, y3] = mods[k];

                ll c1 = cnt[x1][y1], c2 = cnt[x2][y2], c3 = cnt[x3][y3];
                c2 -= (i == j);
                c3 -= (i == k);
                c3 -= (k == j);

                ckmax(c2, 0);
                ckmax(c3, 0);

                int b1 = get(x1, y1, x2, y2);
                int b2 = get(x1, y1, x3, y3);
                int b3 = get(x3, y3, x2, y2);

                if ((b1 + b2 + b3) % 4 == 0)
                    ans += c1 * c2 * c3;
            }
        }
    }

    // print(ans);

    print(ans / 6);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
        solve();
}

