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

using ld = long double;
const ld eps = 1e-12;
ld ans, c, m, p, v, dp[11][11];
array<ld, 2> prob[20][20];

void go(int d = 0, ld cp = c, ld mp = m, ld pp = p, ld cur = 1) {
    //print(d, cp, mp, pp);
    ans += cur * pp * (d + 1);

    if (cp >= v) {
        if (mp > eps)
            go(d + 1, cp - v, mp + 0.5 * v, pp + 0.5 * v, cur * cp);
        else
            go(d + 1, cp - v, 0, pp + v, cur * cp);
    }
    else if (cp > eps) {
        if (mp > eps)
            go(d + 1, 0, mp + 0.5 * cp, pp + 0.5 * cp, cur * cp);
        else
            go(d + 1, 0, 0, pp + cp, cur * cp);
    }
    if (mp >= v) {
        if (cp > eps)
            go(d + 1, cp + 0.5 * v, mp - v, pp + 0.5 * v, cur * mp);
        else
            go(d + 1, 0, mp - v, pp + v, cur * mp);
    }
    else if (mp > eps) {
        if (cp > eps)
            go(d + 1, cp + 0.5 * mp, 0, pp + 0.5 * mp, cur * mp);
        else
            go(d + 1, 0, 0, pp + mp, cur * mp);
    }
}

void solve() {
    read(c, m, p, v);

    /*
    for (int i = 0; i <= 10; ++i)
        for (int j = 0; j <= 10; ++j)
            dp[i][j] = prob[i][j][0] = prob[i][j][1] = 0;

    prob[0][0] = {c, m};
    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            if (prob[i][j][0] >= v) {
                prob[i + 1][j][0] = prob[i][j][0] - v;
                if (prob[i][j][1] > 0)
                    prob[i + 1][j][1] = prob[i][j][1] + 0.5 * v;
            }
            else {
                prob[i + 1][j][0] = 0;
                if (prob[i][j][1] > 0)
                    prob[i + 1][j][1] = prob[i][j][1] + 0.5 * prob[i][j][0];
            }

            if (prob[i][j][1] >= v) {
                prob[i][j + 1][1] = prob[i][j][1] - v;
                if (prob[i][j][0] > 0)
                    prob[i][j + 1][0] = prob[i][j][0] + 0.5 * v;
            }
            else {
                prob[i + 1][j][1] = 0;
                if (prob[i][j][0] > 0)
                    prob[i + 1][j][0] = prob[i][j][0] + 0.5 * prob[i][j][1];
            }
        }
    }

    dp[0][0] = 1;
    for (int i = 0; i <= 10; ++i) {
        for (int j = 0; j <= 10; ++j) {
            if (i < 10)
                dp[i + 1][j] += dp[i][j] * prob[i][j][0];
            if (j < 10)
                dp[i][j + 1] += dp[i][j] * prob[i][j][1];
        }
    }

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            cout << prob[i][j][0] << " " << prob[i][j][1] << "\t\n"[j == 9];

    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            cout << dp[i][j] << "\t\n"[j == 9];

    ld ans = 0;
    for (int i = 0; i <= 10; ++i)
        for (int j = 0; j <= 10; ++j)
            ans += dp[i][j] * (i + j + 1) * (1 - prob[i][j][0] - prob[i][j][1]);
    */
    ans = 0;
    go();

    cout << setprecision(12) << fixed << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
