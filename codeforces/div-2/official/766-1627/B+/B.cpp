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

const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> d(n, vector<int>(m, -1));

    queue<array<int, 2>> q;
    d[0][0] = 0;
    q.push({0, 0});
    if (n > 1) {
        d[n - 1][0] = 0;
        q.push({n - 1, 0});
    }
    if (m > 1) {
        d[0][m - 1] = 0;
        q.push({0, m - 1});
    }
    if (n > 1 && m > 1) {
        d[n - 1][m - 1] = 0;
        q.push({n - 1, m - 1});
    }

    while (q.size()) {
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && d[nr][nc] < 0) {
                d[nr][nc] = d[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    map<int, int, greater<int>> mp;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ++mp[d[i][j]];

    for (auto [dist, cnt] : mp) {
        while (cnt--)
            cout << n + m - 2 - dist << " ";
    }

    cout << '\n';
    
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

