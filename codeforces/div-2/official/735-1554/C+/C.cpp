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
    ll n, m;
    read(n, m);

    if (n > m)
        finish(0);

    // print(bitset<10>(123456));
    // print(bitset<10>(654321));
    // print(bitset<10>(530866));

    // lowest x such that n ^ x > m
    ll ans = 0;
    for (int i = 31; ~i; --i) {
        if ((m & (1 << i)) && !(n & (1 << i)))
            ans |= (1 << i);
        else if ((n & (1 << i)) && !(m & (1 << i)))
            break;
    }

    // print(bitset<10>(ans));

    if ((ans ^ n) == m) {
        for (int i = 0; i <= 31; ++i) {
            if (!(n & (1 << i)) && !(m & (1 << i))) {
                ans |= (1 << i);
                break;
            } else if ((ans & (1 << i)) && (m & (1 << i))) {
                ans ^= (1 << i);
            }
        }
    }

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}


