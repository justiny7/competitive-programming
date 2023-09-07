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

struct Graph {
    int n;
    vector<int> a, par, vis, topo;
    vector<vector<int>> cyc;
    vector<ll> c;

    void dfs(int v) {
        vis[v] = 1;
        if (!vis[a[v]]) {
            par[a[v]] = v;
            dfs(a[v]);
        } else if (vis[a[v]] == 1) {
            cyc.push_back({v});
            
            int x = v;
            // print("found cyc starting at", v, "and ends at", a[v]);
            while (par[x] != a[v]) {
                // print(x);
                cyc.back().push_back(x = par[x]);
            }
            cyc.back().push_back(a[v]);
        }

        vis[v] = 2;
    }
    void dfs_res(int v) {
        vis[v] = 1;
        if (~a[v] && !vis[a[v]])
            dfs_res(a[v]);
        topo.push_back(v);
    }

    void solve() {
        read(n);

        a.resize(n);
        c.resize(n);
        read(a, c);

        for (int &i : a)
            --i;

        par.resize(n);
        vis.resize(n);
        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs(i);

        for (auto v : cyc) {
            int x = v[0];
            for (int u : v)
                if (c[u] < c[x])
                    x = u;

            // print("rem", x);
            a[x] = -1;
        }

        vis.assign(n, 0);
        for (int i = 0; i < n; i++)
            if (!vis[i])
                dfs_res(i);

        reverse(all(topo));
        for (int &i : topo)
            i++;

        print(topo);
    }
};

void solve() {
    Graph g;
    g.solve();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

