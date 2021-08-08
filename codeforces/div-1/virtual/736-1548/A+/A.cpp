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

const int N = 2e5 + 69;
int n, m, q, cur;
set<int> adj[N];
bool vul[N];

void solve() {
    read(n, m);

    while (m--) {
        int u, v;
        read(u, v);
        adj[u].insert(v);
        adj[v].insert(u);
    }

    for (int i = 1; i <= n; ++i) {
        if (adj[i].empty() || *adj[i].rbegin() < i)
            ++cur;
        else
            vul[i] = 1;
    }

    read(q);
    while (q--) {
        int t;
        read(t);

        if (t == 1) {
            int u, v;
            read(u, v);

            adj[u].insert(v);
            adj[v].insert(u);

            if (!vul[u] && *adj[u].rbegin() > u) {
                vul[u] = 1;
                --cur;
            }
            if (!vul[v] && *adj[v].rbegin() > v) {
                vul[v] = 1;
                --cur;
            }
        } else if (t == 2) {
            int u, v;
            read(u, v);

            adj[u].erase(v);
            adj[v].erase(u);

            if (vul[u] && (adj[u].empty() || *adj[u].rbegin() < u)) {
                vul[u] = 0;
                ++cur;
            }
            if (vul[v] && (adj[v].empty() || *adj[v].rbegin() < v)) {
                vul[v] = 0;
                ++cur;
            }
        } else {
            print(cur);
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    // int t; read(t);
    // while (t--)
        solve();
}

