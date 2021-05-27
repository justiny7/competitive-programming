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

const int N = 3e5 + 69;
int n, ans, cur, tin[N], tout[N], tt;
vector<int> adj1[N], adj2[N];

//Segtree {{{
int t[N * 4], lz[N * 4];

void reset(int l = 0, int r = n - 1, int v = 1) {
    t[v] = 0, lz[v] = -1;
    if (l != r) {
        int m = l + r >> 1;
        reset(l, m, v * 2);
        reset(m + 1, r, v * 2 + 1);
    }
}
void push(int l, int r, int v) {
    if (~lz[v] && l != r) {
        t[v * 2] = t[v * 2 + 1] = lz[v];
        lz[v * 2] = lz[v * 2 + 1] = lz[v];
    }
    lz[v] = -1;
}
void upd(int ql, int qr, int x, int l = 0, int r = n - 1, int v = 1) {
    if (l > qr || r < ql)
        return;
    if (l >= ql && r <= qr) {
        t[v] = lz[v] = x;
        return;
    }
    push(l, r, v);
    int m = l + r >> 1;
    upd(ql, qr, x, l, m, v * 2);
    upd(ql, qr, x, m + 1, r, v * 2 + 1);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}
int query(int ql, int qr, int l = 0, int r = n - 1, int v = 1) {
    if (l > qr || r < ql)
        return 0;
    if (l >= ql && r <= qr)
        return t[v];
    push(l, r, v);
    int m = l + r >> 1;
    return max(query(ql, qr, l, m, v * 2), query(ql, qr, m + 1, r, v * 2 + 1));
}
//}}}

bool anc(int u, int v) {
    return (tin[u] <= tin[v] && tout[u] >= tout[v]);
}
void dfs(int v = 1) {
    //print("at node ", v, "at time", tt);
    tin[v] = tt++;
    for (int u : adj2[v])
        dfs(u);
    tout[v] = tt - 1;
}
void dfs2(int v = 1) {
    int p = query(tin[v], tout[v]);
    //print("querying node", v, "from time", tin[v], tout[v]);
    //print("anc of", v, "is", p);
    if (p && anc(p, v)) {
        //print("updating", p, v);
        upd(tin[p], tout[p], 0);
        upd(tin[v], tout[v], v);
    }
    else if (!p) {
        ++cur;
        upd(tin[v], tout[v], v);
    }
    ckmax(ans, cur);
    for (int u : adj1[v])
        dfs2(u);
    if (p && anc(p, v)) {
        upd(tin[v], tout[v], 0);
        upd(tin[p], tout[p], p);
    }
    else if (!p) {
        --cur;
        upd(tin[v], tout[v], 0);
    }
}

void solve() {
    read(n);
    tt = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        adj1[i].clear();
        adj2[i].clear();
    }
    for (int i = 2; i <= n; ++i) {
        int p; read(p);
        adj1[p].push_back(i);
    }
    for (int i = 2; i <= n; ++i) {
        int p; read(p);
        adj2[p].push_back(i);
    }
    reset();
    dfs(); dfs2();
    //for (int i = 1; i <= n; ++i)
    //print(i, tin[i], tout[i]);
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
}
