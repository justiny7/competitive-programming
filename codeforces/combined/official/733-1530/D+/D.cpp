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

const int N = 2e5 + 69;
int n, to[N], par[N], ans[N];
bool vis[N], took[N], bd[N];

void dfs(int v) {
    vis[v] = 1;

    int u = to[v];
    if (par[u] < 0) {
        par[u] = v;
        took[v] = 1;
    }
    if (!vis[u])
        dfs(u);
}

void solve() {
    read(n);
    for (int i = 1; i <= n; ++i) {
        read(to[i]);
        par[i] = -1;
        vis[i] = took[i] = bd[i] = 0;
    }

    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i);

    vector<int> need, cyc;
    int c = 0;
    for (int i = 1; i <= n; ++i) {
        //print(i, took[i], par[i]);
        if (par[i] < 0 && !took[i])
            cyc.push_back(i), bd[i] = 1;
        else if (par[i] < 0)
            need.push_back(i);
        else
            ++c;
    }

    for (int i = 1, j = 0; i <= n; ++i)
        if (!took[i] && !bd[i])
            to[i] = need[j++];

    if (cyc.size() > 1) {
        for (int i = 0; i < cyc.size(); ++i)
            to[cyc[i]] = cyc[(i + 1) % cyc.size()];
    }
    else if (cyc.size()) {
        int v = cyc[0];
        int ch = par[to[v]];
        to[ch] = v;
    }

    print(c);
    for (int i = 1; i <= n; ++i)
        write(to[i], " \n"[i == n]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
