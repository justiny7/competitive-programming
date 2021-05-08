#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T>> &v) { string s; for (T i : v) o << s << i, s = "\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S>> &v) { string s; for (T i : v) o << s << i, s = "\n"; return o; }

template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T i : v) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T>> &v) { string s; for (T i : v) o << s << i, s = "\n"; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

//Misc
template<class T> bool ckmin(T &a, const T b) { return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T &a, const T b) { return (a < b ? a = b, 1 : 0); }

using ll = long long;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Constants
const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 1e5 + 69, L = 19;
int n, q, dep[N], lift[N][L];
vector<int> adj[N];

void dfs(int v = 1, int p = 0, int d = 0) {
    dep[v] = d, lift[v][0] = p;
    for (int i = 1; i < L; ++i)
        lift[v][i] = lift[lift[v][i - 1]][i - 1];
    for (int u : adj[v])
        if (u != p)
            dfs(u, v, d + 1);
}
int lca(int u, int v) {
    if (dep[u] < dep[v])
        swap(u, v);
    int dif = dep[u] - dep[v];
    for (int i = L - 1; ~i; --i)
        if (dif & (1 << i))
            u = lift[u][i];
    if (u == v)
        return u;
    for (int i = L - 1; ~i; --i)
        if (lift[v][i] != lift[u][i])
            v = lift[v][i], u = lift[u][i];
    return lift[v][0];
}
int dist(int u, int v) {
    int l = lca(u, v);
    //print("!", u, v, l);
    return (dep[u] + dep[v] - 2 * dep[l]);
}

void solve() {
    read(n);
    for (int i = 1, u, v; i < n; ++i) {
        read(u, v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs();
    read(q);
    while (q--) {
        int x, y, a, b, k;
        read(x, y, a, b, k);
        int od = dist(a, b);
        //print(">", a, b, od);
        bool f = 0;
        if (((od & 1) == (k & 1)) && od <= k)
            f = 1;
        else {
            for (int t = 0; t < 2; ++t) {
                int nd = dist(a, x) + dist(b, y) + 1;
                //print("?", a, b, nd);
                if (((nd & 1) == (k & 1)) && nd <= k)
                    f = 1;
                swap(x, y);
            }
        }
        print((f ? "YES" : "NO"));
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
    solve();
}
