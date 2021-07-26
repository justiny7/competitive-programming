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
    ll a, b;
    read(a, b);

    vector<ll> adiv, bdiv;
    for (ll i = 1; i * i <= a; ++i)
        if (a % i == 0)
            adiv.push_back(i);
    for (ll i = 1; i * i <= b; ++i)
        if (b % i == 0)
            bdiv.push_back(i);

    ll tot = a + b, ans = LLONG_MAX;
    int aptr = 0, bptr = 0;
    for (ll i = 1; i * i <= tot; ++i) {
        if (tot % i)
            continue;

        while (aptr + 1 < adiv.size() && adiv[aptr + 1] <= i)
            ++aptr;
        while (bptr + 1 < bdiv.size() && bdiv[bptr + 1] <= i)
            ++bptr;

        ll mn = min(a / adiv[aptr], b / bdiv[bptr]);
        if (mn <= tot / i)
            ckmin(ans, 2 * (i + tot / i));
    }

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
    solve();
}
