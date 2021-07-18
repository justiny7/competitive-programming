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

const int N = 4e5 + 69;
int n, m, cmp, dp[N][2], scc[N];
vector<int> adj[N], radj[N], cmps[N], ord;
set<int> tadj[N], self;
bool vis[N], inf[N], psh[N];

void dfs_ord(int v) {
    vis[v] = 1;
    for (int u : adj[v])
        if (!vis[u])
            dfs_ord(u);
    ord.push_back(v);
}
void dfs_cmp(int v) {
    scc[v] = cmp;
    cmps[cmp].push_back(v);

    for (int u : radj[v])
        if (!scc[u])
            dfs_cmp(u);
}
void dfs_ans(int v, int c) {
    //print(v, c);
    for (int u : tadj[v]) {
        if (inf[v]) {
            if (!psh[u]) {
                dp[u][0] = inf[u] = psh[u] = 1;
                dfs_ans(u, c);
            }
        }
        else if (c == 0) {
            if (!dp[u][0]) {
                dp[u][0] = 1;
                dfs_ans(u, 0);
            }
            else if (!dp[u][1]) {
                dp[u][1] = 1;
                dfs_ans(u, 1);
            }
        }
        else if (c == 1) {
            if (!dp[u][1]) {
                dp[u][1] = 1;
                dfs_ans(u, 1);
            }
        }
    }
}

void solve() {
    read(n, m);

    cmp = 0;
    self.clear(); ord.clear();
    for (int i = 1; i <= n; ++i) {
        scc[i] = vis[i] = dp[i][0] = dp[i][1] = inf[i] = psh[i] = 0;
        adj[i].clear();
        radj[i].clear();
        tadj[i].clear();
        cmps[i].clear();
    }

    while (m--) {
        int u, v;
        read(u, v);
        if (u == v)
            self.insert(v);
        else {
            adj[u].push_back(v);
            radj[v].push_back(u);
        }
    }

    //print("SELF:");
    //for (int i : self)
    //write(i, " ");
    //print();

    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs_ord(i);
    for (int i = n - 1; ~i; --i) {
        int v = ord[i];
        if (!scc[v])
            ++cmp, dfs_cmp(v);
    }

    for (int v = 1; v <= n; ++v)
        for (int u : adj[v])
            if (scc[u] != scc[v])
                tadj[scc[v]].insert(scc[u]);

    for (int i = 1; i <= cmp; ++i)
        if (cmps[i].size() > 1 || self.count(cmps[i][0]))
            inf[i] = 1;

    //for (int i = 1; i <= n; ++i)
    //print(">", i, scc[i]);

    //for (int i = 1; i <= cmp; ++i)
    //print("!", i, inf[i]);

    if (dp[scc[1]][0] == 0)
        dp[scc[1]][0] = 1;

    if (inf[1])
        psh[1] = 1;

    dfs_ans(scc[1], 0);

    for (int i = 1; i <= n; ++i) {
        int s = scc[i];
        if ((dp[s][0] || dp[s][1]) && inf[s])
            write(-1);
        else if (dp[s][1])
            write(2);
        else if (dp[s][0])
            write(1);
        else
            write(0);
        write(" \n"[i == n]);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
