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

void solve() {
    int n, m;
    read(n, m);

    vector<array<int, 2>> srt, not_srt;
    while (m--) {
        int t, l, r;
        read(t, l, r), --l, --r;

        if (t)
            srt.push_back({l, r});
        else
            not_srt.push_back({l, r});
    }

    vector<bool> must_srt(n + 1); // must_srt[i] = i -> i + 1 has to increase
    for (auto [l, r] : srt)
        for (int i = l; i < r; ++i)
            must_srt[i] = 1;

    for (auto [l, r] : not_srt) {
        bool f = 0;
        for (int i = l; i < r; ++i)
            f |= !must_srt[i];

        if (!f)
            finish("NO");
    }

    print("YES");
    int cur = 5e5;
    write(cur);
    for (int i = 0; i < n - 1; ++i) {
        if (must_srt[i])
            write(' ', ++cur);
        else
            write(' ', --cur);
    }
    print();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
    solve();
}
