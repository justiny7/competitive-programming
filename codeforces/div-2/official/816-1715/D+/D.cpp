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

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, q;
    read(n, q);

    vector<int> res(n, (1 << 30) - 1);
    vector<vector<array<int, 2>>> adj(n);
    vector<vector<char>> fix(n, vector<char>(30));

    vector<array<int, 3>> qu(q);
    for(auto &v : qu) {
        read(v), --v[0], --v[1];

        if (v[0] > v[1])
            swap(v[0], v[1]);

        if (v[0] == v[1]) {
            res[v[0]] = v[2];
            for (int i = 0; i < 30; ++i)
                if (v[2] & (1 << i))
                    fix[v[0]][i] = 1;
        } else {
            adj[v[0]].push_back({v[1], v[2]});
            res[v[0]] &= v[2];
            res[v[1]] &= v[2];
        }
    }

    // print(res);

    for (int i = 0; i < n; ++i) {
        for (int j = 29; ~j; --j) {
            if (!fix[i][j] && (res[i] & (1 << j))) {
                bool f = 1;
                for (auto [u, x] : adj[i]) {
                    // print(">", (res[i] ^ (1 << j)) | res[u], x);
                    f &= (((res[i] ^ (1 << j)) | res[u]) == x);
                }

                // print(i, j, f);

                if (f) {
                    res[i] ^= (1 << j);
                    for (auto [u, x] : adj[i])
                        if (x & (1 << j))
                            fix[u][j] = 1;
                }
            } else if (!(res[i] & (1 << j))) {
                for (auto [u, x] : adj[i])
                    if (x & (1 << j))
                        fix[u][j] = 1;
            }
        }
    }

    print(res);
}

