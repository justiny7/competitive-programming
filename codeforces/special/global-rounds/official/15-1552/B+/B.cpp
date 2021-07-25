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

const int N = 5e4 + 69;
map<int, int> mp[N];

void solve() {
    int n; read(n);

    for (int i = 0; i < n; ++i)
        mp[i].clear();

    vector<vector<array<int, 2>>> races(5);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            int x; read(x);
            races[j].push_back({x, i});
        }
    }

    vector<vector<int>> pos(n, vector<int>(5));
    for (int i = 0; i < 5; ++i) {
        sort(all(races[i]));
        for (int j = 0; j < n; ++j)
            pos[races[i][j][1]][i] = j;
    }


    vector<int> inds(n);
    iota(all(inds), 0);
    sort(all(inds), [&](int a, int b) {
        int c = 0;
        for (int i = 0; i < 5; ++i)
            c += pos[a][i] < pos[b][i];

        return c >= 3;
    });

    // print(inds);

    int cand = inds[0];
    bool f = 1;
    for (int i = 0; i < n; ++i) {
        if (i == cand)
            continue;

        int c = 0;
        for (int j = 0; j < 5; ++j)
            c += pos[cand][j] < pos[i][j];

        f &= (c >= 3);
    }

    print(f ? cand + 1 : -1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
