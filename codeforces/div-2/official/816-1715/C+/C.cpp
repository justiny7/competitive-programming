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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    read(n, m);

    vector<int> a(n);
    read(a);

    ll res = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1])
            continue;
        res += 1LL * i * (n - i);
    }

    auto rem = [&](int i) {
        if (i > 0 && a[i] != a[i - 1])
            res -= 1LL * i * (n - i);
        if (i < n - 1 && a[i] != a[i + 1])
            res -= 1LL * (i + 1) * (n - i - 1);
    };
    auto add = [&](int i, int x) {
        a[i] = x;
        if (i > 0 && a[i] != a[i - 1])
            res += 1LL * i * (n - i);
        if (i < n - 1 && a[i] != a[i + 1])
            res += 1LL * (i + 1) * (n - i - 1);
    };

    res += 1LL * n * (n + 1) / 2;

    while (m--) {
        int i, x;
        read(i, x), --i;

        rem(i);
        add(i, x);

        print(res);
    }

}
