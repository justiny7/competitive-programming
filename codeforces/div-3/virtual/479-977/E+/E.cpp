#include <bits/stdc++.h>
using namespace std;

//TEMPLATE {{{

//Macros
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define finish(...) return void(print(__VA_ARGS__))
#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)

//Input
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { for (T &i : a) read(i); }

template<class T> void read(vector<T> &v) { for (T &i : v) read(i); }
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

//Output
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; for (T i : a) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T i : v) o << s << i, s = " "; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

//Misc
template<class T> bool ckmin(T &a, const T b) { return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T &a, const T b) { return (a < b ? a = b, 1 : 0); }

using ll = long long;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Constants
const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 2e5 + 69;
int n, m, c, cmp[N], sz[N], mk[N];
vector<int> adj[N], vcmp[N];
vector<pair<int, int>> edges, ecmp[N];

void dfs(int v) {
    cmp[v] = c;
    for (int u : adj[v])
        if (!cmp[u])
            dfs(u);
}

void solve() {
    read(n, m);
    while (m--) {
        int u, v;
        read(u, v);
        edges.emplace_back(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        if (!cmp[i])
            ++c, dfs(i);
    for (int i = 1; i <= n; ++i) {
        vcmp[cmp[i]].push_back(i);
        ++sz[cmp[i]];
    }
    for (auto [u, v] : edges) {
        --sz[cmp[u]];
        ecmp[cmp[u]].emplace_back(u, v);
    }
    int ans = 0;
    for (int i = 1; i <= c; ++i) {
        if (sz[i] == 0) {
            for (auto [u, v] : ecmp[i])
                ++mk[u], ++mk[v];
            bool f = 1;
            for (auto v : vcmp[i])
                f &= (mk[v] == 2);
            ans += f;
        }
    }
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
    solve();
}
