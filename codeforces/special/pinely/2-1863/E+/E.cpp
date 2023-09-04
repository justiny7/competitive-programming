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
    int n, m;
    ll k;
    vector<int> h;
    vector<array<int, 2>> dep;

    vector<ll> in, dp;
    vector<vector<array<ll, 2>>> adj;
    vector<array<ll, 2>> segs;

    void get_segs() {
        vector<int> st;
        for (int i = 1; i <= n; ++i)
            if (in[i] == 0)
                st.push_back(i);

        for (int i = n; i > 0; --i) {
            for (auto [u, d] : adj[i])
                ckmax(dp[i], dp[u] + d);
        }

        for (int v : st)
            segs.push_back({h[v], dp[v]});
    }

    void go() {
        read(n, m, k);

        h.resize(n + 1);
        for (int i = 1; i <= n; ++i)
            read(h[i]);
        dep.resize(m);
        read(dep);

        in.resize(n + 1);
        dp.resize(n + 1);
        adj.resize(n + 1);
        for (auto [u, v] : dep) {
            ++in[v];
            if (h[v] >= h[u])
                adj[u].push_back({v, h[v] - h[u]});
            else
                adj[u].push_back({v, h[v] + k - h[u]});
        }

        get_segs();
        
        sort(segs.begin(), segs.end());

        multiset<ll> ens;
        for (auto [st_t, len] : segs)
            ens.insert(st_t + len);

        ll res = LLONG_MAX;
        for (auto [st_t, len] : segs) {
            ckmin(res, *ens.rbegin() - st_t);
            ens.erase(ens.find(st_t + len));
            ens.insert(st_t + len + k);
        }

        print(res);
    }
};

void solve() {
    Graph g;
    g.go();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

