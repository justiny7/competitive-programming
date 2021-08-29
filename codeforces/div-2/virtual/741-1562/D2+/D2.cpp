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
    int n, q;
    string s;
    read(n, q, s);

    vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
        int here = (s[i] == '+' ? 1 : -1) * ((i & 1) ? 1 : -1);
        a[i + 1] = a[i] + here;
    }

    map<int, vector<int>> vals;
    for (int i = 1; i <= n; ++i)
        vals[a[i]].push_back(i);

    auto get = [&](int l, int r) -> int {
        int here = a[r] - a[l - 1];
        int need = (here + (here > 0 ? 1 : -1)) / 2 + a[l - 1];

        auto it = lower_bound(all(vals[need]), l);
        assert(it != vals[need].end() && *it <= r);
        return *it;
    };

    while (q--) {
        int l, r;
        read(l, r);

        int here = a[r] - a[l - 1];
        if (!here)
            print(0);
        else if (here & 1) {
            print(1);
            print(get(l, r));
        } else {
            print(2);
            print(get(l, r - 1), r);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

