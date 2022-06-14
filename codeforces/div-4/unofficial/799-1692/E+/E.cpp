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
    int n, s;
    read(n, s);

    vector<int> a(n);
    read(a);

    int tot = 0;
    for (int x : a)
        tot += x;

    if (tot < s)
        finish(-1);

    int take = tot - s;

    vector<int> pref(n + 1, -1), suff(n + 1, -1);
    pref[0] = suff[0] = 0;
    int pp = 0, ss = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i])
            ++pp;
        if (a[n - i - 1])
            ++ss;

        if (pref[pp] < 0)
            pref[pp] = i + 1;
        if (suff[ss] < 0)
            suff[ss] = i + 1;
    }

    int res = INT_MAX;
    for (int i = 0; i <= take; ++i) {
        int j = take - i;

        if (~pref[i] && ~suff[j])
            ckmin(res, pref[i] + suff[j]);
    }

    print(res);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

