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
    int n;
    read(n);

    vector<vector<array<int, 2>>> adj(n + 1);
    for (int i = 1, u, v; i < n; ++i) {
        read(u, v);
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    bool f = 1;
    int st = -1;
    for (int i = 1; i <= n; ++i) {
        f &= (adj[i].size() < 3);
        if (adj[i].size() == 1)
            st = i;
    }

    if (!f)
        finish(-1);

    assert(~st);
    int par = 0, lst = 5;
    vector<int> res(n);
    for (int t = 1; t < n; ++t) {
        for (auto [u, i] : adj[st]) {
            if (u != par) {
                res[i] = (7 - lst);
                lst = (7 - lst);
                par = st;
                st = u;
                break;
            }
        }
    }

    for (int i = 1; i < n; ++i)
        write(res[i], " \n"[i == n - 1]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

