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
    string s;
    read(s);

    map<char, int> mp;
    for (char c : s)
        ++mp[c];

    int n = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (!mp.count(c))
            break;
        if (mp[c] != 1)
            finish("NO");

        ++n;
    }

    if (n != s.size())
        finish("NO");

    int l, r;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'a') {
            l = r = i;
            break;
        }
    }

    char cur = 'b';
    while (l > 0 || r < n - 1) {
        if (l > 0 && s[l - 1] == cur)
            --l;
        else if (r < n - 1 && s[r + 1] == cur)
            ++r;
        else
            finish("NO");

        ++cur;
    }

    print("YES");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
