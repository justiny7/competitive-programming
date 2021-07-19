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

// answer for starting node v is sum of all subtree sizes rooted at v
const int N = 2e5 + 69;
int n; ll tot, ans, sz[N];
vector<int> adj[N];

void dfs(int v = 1, int p = 0) {
    sz[v] = 1;

    for (int u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            sz[v] += sz[u];
        }
    }

    tot += sz[v];
}
void reroot(int v = 1, int p = 0) {
    ans = max(ans, tot);

    for (int u : adj[v]) {
        if (u == p)
            continue;

        sz[v] -= sz[u];
        tot -= sz[u];
        sz[u] += sz[v];
        tot += sz[v];

        reroot(u, v);

        tot -= sz[v];
        sz[u] -= sz[v];
        tot += sz[u];
        sz[v] += sz[u];
    }
}

void solve() {
    read(n);

    for (int i = 1, u, v; i < n; ++i) {
        read(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs();
    reroot();

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
    solve();
}
