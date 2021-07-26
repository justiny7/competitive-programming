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

const int N = 2e5 + 69;
int n, par[N];
vector<int> adj[N];
array<int, 2> dep[N];
bool ok[N];

void dfs(int v = 1, int p = 0, int d = 0) {
    dep[v] = {d, v}, par[v] = p;

    for (int u : adj[v])
        if (u != p)
            dfs(u, v, d + 1);
}

void solve() {
    read(n);

    for (int i = 1, u, v; i < n; ++i) {
        read(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();

    sort(dep + 1, dep + n + 1);

    int ans = 0;
    for (int i = n; i; --i) {
        auto [d, v] = dep[i];
        if (ok[v] || d <= 2)
            continue;

        int nxt = par[v];
        ok[nxt] = 1;
        for (int u : adj[nxt])
            ok[u] = 1;

        ++ans;
    }

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
    solve();
}
