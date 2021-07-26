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
    int n; read(n);

    vector<ll> lpref(n + 2), lsuff(n + 2), rpref(n + 2, 2e9), rsuff(n + 2, 2e9);
    for (int i = 1; i <= n; ++i) {
        ll l, r;
        read(l, r);

        lpref[i] = lsuff[i] = l;
        rpref[i] = rsuff[i] = r;
    }

    for (int i = 1; i <= n; ++i) {
        ckmax(lpref[i], lpref[i - 1]);
        ckmin(rpref[i], rpref[i - 1]);
    }
    for (int i = n; i; --i) {
        ckmax(lsuff[i], lsuff[i + 1]);
        ckmin(rsuff[i], rsuff[i + 1]);
    }

    /*
    print(lpref);
    print(lsuff);
    print(rpref);
    print(rsuff);
    */

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
        ckmax(ans, min(rpref[i - 1], rsuff[i + 1]) - max(lpref[i - 1], lsuff[i + 1]));

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
    solve();
}
