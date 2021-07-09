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

const int N = 5e3 + 69;
int n, m, vis[N], ans[N];
vector<array<int, 2>> adj[N];
bool cyc;

void dfs(int v) {
    vis[v] = 1;

    for (auto [u, id] : adj[v]) {
        if (vis[u] == 1) {
            ans[id] = 2;
            cyc = 1;
        }
        else {
            ans[id] = 1;
            if (!vis[u])
                dfs(u);
        }
    }

    vis[v] = 2;
}

void solve() {
    read(n, m);

    for (int i = 0; i < m; ++i) {
        int u, v;
        read(u, v);
        adj[u].push_back({v, i});
    }

    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs(i);

    if (cyc) {
        print(2);
        for (int i = 0; i < m; ++i)
            write(ans[i], " \n"[i == m - 1]);
    }
    else {
        print(1);
        print(vector<int>(m, 1));
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    //int t; read(t);
    //while (t--)
    solve();
}
