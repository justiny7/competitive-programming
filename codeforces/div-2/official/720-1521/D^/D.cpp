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

#define FIT(i, x) for (auto (i) = (x).begin(); (i) != (x).end(); ++(i))
#define RIT(i, x) for (auto (i) = (x).rbegin(); (i) != (x).rend(); ++(i))

//Input
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { for (T &i : a) read(i); }

template<class T> void read(vector<T> &v) { for (T &i : v) read(i); }
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

//Output
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; for (T &i : a) o << s << i, s = " "; return o; }

template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T>> &v) { string s; for (T &i : v) o << s << i, s = "\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S>> &v) { string s; for (T &i : v) o << s << i, s = "\n"; return o; }

template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T &i : v) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T>> &v) { string s; for (T &i : v) o << s << i, s = "\n"; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

//Misc
template<class T> bool ckmin(T &a, const T &b) { return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T &a, const T &b) { return (a < b ? a = b, 1 : 0); }

using ll = long long;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Constants
const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 1e5 + 69;
int n, dist[N], par[N], pp[N], mx = 1;
vector<int> adj[N];
map<int, vector<int>> mp;
map<int, int> hh, tt, tp;

int find(int v) {
    return (v == pp[v] ? v : pp[v] = find(pp[v]));
}
bool merge(int u, int v) {
    if ((u = find(u)) == (v = find(v)))
        return 0;
    pp[u] = v;
    return 1;
}

int dfs(int v = 1, int p = 0, int d = 0) {
    int cur = -1;
    dist[v] = d, par[v] = p;
    for (int u : adj[v]) {
        if (u == p)
            continue;
        int here = dfs(u, v, d + 1);
        if (here < 0)
            continue;
        if (cur == -1)
            cur = here;
        else if (cur != -2) {
            merge(cur, here);
            merge(cur, v);
            //print("merging", cur, here, v, "into", find(v));
            hh[find(v)] = cur;
            tt[find(v)] = here;
            tp[find(v)] = v;
            cur = -2;
        }
        else {
            //print("merging", here, v, v, "into", find(v));
            hh[find(here)] = here;
            tt[find(here)] = tp[find(here)] = u;
        }
    }
    if (cur == -1)
        return v;
    if (cur >= 0)
        merge(v, cur);
    //print("%", v, cur);
    return cur;
}

void solve() {
    mp.clear(); hh.clear(); tt.clear(); tp.clear();
    read(n);
    for (int i = 1; i <= n; ++i) {
        adj[i].clear();
        pp[i] = i;
    }
    for (int i = 1, u, v; i < n; ++i) {
        read(u, v);
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    int ret = dfs();
    //print("RET", ret);
    if (ret >= 0) {
        hh[find(1)] = tp[find(1)] = 1;
        tt[find(1)] = ret;
    }
    else if (ret == -1)
        tt[find(1)] = 1;
    for (int i = 1; i <= n; ++i) {
        //print(">", i, find(i));
        mp[find(i)].push_back(i);
    }
    /*
    for (auto [i, v] : mp) {
        print(i);
        print(v);
        print(hh[i], tt[i], tp[i]);
    }
    */
    if (mp.size() == 1)
        finish(0);
    vector<array<int, 4>> ops;
    int lst = find(1);
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        auto [x, v] = *it;
        if (x == find(1))
            continue;
        //print(x, lst);
        ops.push_back({tp[x], par[tp[x]], hh[x], tt[lst]});
        lst = x;
    }
    print(ops.size());
    for (auto i : ops)
        print(i);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
}
