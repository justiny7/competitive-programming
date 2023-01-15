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

int msb(ll x) {
    int res = -1;
    while (x) {
        x >>= 1;
        ++res;
    }
    return res;
}

ll calc(ll x, ll y) {
    ll res = 0;

    while (x && y) {
        int x_msb = msb(x),
            y_msb = msb(y);

        if (x_msb != y_msb)
            break;

        ll add = 1LL << x_msb;
        res |= add;
        x -= add, y -= add;
    }
    return res;
}

void solve() {
    ll n, x;
    read(n, x);

    if (x > n)
        finish(-1);

    ll lo = n, hi = 5e18, best = -1;
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2;

        ll here = calc(n, mid);
        if (here <= x) {
            best = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }

        // print(lo, hi, mid, here);
    }

    if (~best && calc(n, best) == x)
        print(best);
    else
        print(-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

