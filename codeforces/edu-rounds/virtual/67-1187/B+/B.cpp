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
    int n; string s;
    read(n, s);

    vector<vector<int>> pref(n + 1, vector<int>(26));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 26; ++j)
            pref[i + 1][j] = pref[i][j] + (s[i] - 'a' == j);

    int q; read(q);
    while (q--) {
        string t; read(t);

        map<char, int> need;
        for (char c : t)
            ++need[c];

        int lo = 1, hi = n;
        while (lo < hi) {
            int m = lo + hi >> 1;

            bool f = 1;
            for (char c = 'a'; c <= 'z'; ++c)
                f &= (need[c] <= pref[m][c - 'a']);

            if (f)
                hi = m;
            else
                lo = m + 1;
        }

        print(lo);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
    solve();
}
