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

//Must be able to reach a central at any point (end on central) ?
//At node v: optimally, x = c - dist[v] bc you can just go to a central and come back
//At v going to u: x - w >= dist[u] --> c - dist[v] - w >= dist[u] --> c >= dist[u] + dist[v] + w
//Replace all edges w/ dist[u] + dist[v] + w, then we're trying to find min(max edge of path)

const int N = 1e5 + 69, Q = 3e5 + 69;
int n, m, k, q, par[N];
set<int> s[N];
ll dist[N], ans[Q];
vector<pair<ll, ll>> adj[N];
vector<array<ll, 3>> edges;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

int find(int v) {
    return (v == par[v] ? v : par[v] = find(par[v]));
}
bool merge(int u, int v, ll w) {
    if ((u = find(u)) == (v = find(v)))
        return 0;
    if (s[u].size() > s[v].size())
        swap(u, v);
    par[u] = v;
    for (auto x : s[u]) {
        if (s[v].count(x)) {
            ans[x] = w;
            s[v].erase(x);
        }
        else
            s[v].insert(x);
    }
    s[u].clear();
    return 1;
}

void solve() {
    memset(dist, 0x3f, sizeof(dist));
    read(n, m, k, q);
    for (int i = 1; i <= n; ++i)
        par[i] = i;
    for (int i = 0; i < m; ++i) {
        int u, v; ll w;
        read(u, v, w);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        edges.push_back({w, u, v});
    }
    for (int i = 0; i < q; ++i) {
        int u, v;
        read(u, v);
        s[u].insert(i);
        s[v].insert(i);
    }
    for (int i = 1; i <= k; ++i) {
        dist[i] = 0;
        pq.emplace(0, i);
    }
    while (pq.size()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d != dist[v])
            continue;
        for (auto [u, w] : adj[v]) {
            if (dist[u] > d + w) {
                dist[u] = d + w;
                pq.emplace(dist[u], u);
            }
        }
    }
    for (auto &[w, u, v] : edges)
        w += dist[u] + dist[v];
    sort(edges.begin(), edges.end());
    for (auto [w, u, v] : edges)
        merge(u, v, w);
    for (int i = 0; i < q; ++i)
        print(ans[i]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
    solve();
}
