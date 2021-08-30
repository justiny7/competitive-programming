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

const int N = 1e3 + 69;
ll n, a[N], pref[N];

ll isect(ll l1, ll r1, ll l2, ll r2) {
    // print(">", l1, r1, l2, r2);
    ll rmn = min(r1, r2), lmx = max(l1, l2);
    return max(0LL, rmn - lmx + 1);
}

void solve() {
    read(n);

    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        if (i % 2 == 0)
            a[i] *= -1;

        pref[i] = pref[i - 1] + a[i];
    }

    ll ans = 0;
    for (int i = 2; i <= n; i += 2) {
        ll l = pref[i], r = pref[i - 1] - 1;

        // print("i at", i);

        ll mn = r;
        for (int j = i - 1; j >= 0; j -= 2) {
            ll ql = pref[j - 1], qr = min(mn, pref[j]);
            ans += isect(l, r, ql, qr);

            ckmin(mn, pref[j - 1]);
        }
    }

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
        solve();
}

