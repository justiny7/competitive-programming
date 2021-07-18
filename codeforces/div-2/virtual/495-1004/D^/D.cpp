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

const int N = 1e6 + 69, INF = 1e9;
int n, mx, x, v[N];

pair<int, int> go(int wid, int len) {
    int y = wid + len - mx - x;
    //print("test", wid, len, x, y);
    if (y >= 0 && x <= wid && y <= len) {
        queue<pair<int, int>> q;
        vector<vector<int>> d(wid, vector<int>(len, -1));
        q.emplace(x - 1, y - 1);
        d[x - 1][y - 1] = 0;
        while (q.size()) {
            auto [r, c] = q.front(); q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i], nc = c + dc[i];
                if (nr >= 0 && nc >= 0 && nr < wid && nc < len && d[nr][nc] < 0) {
                    d[nr][nc] = d[r][c] + 1;
                    q.emplace(nr, nc);
                }
            }
        }

        vector<int> cnts(n + 1);
        for (int i = 0; i < wid; ++i)
            for (int j = 0; j < len; ++j)
                ++cnts[d[i][j]];
        //print(cnts);

        bool f = 1;
        for (int i = 0; i <= mx; ++i)
            f &= (cnts[i] == v[i]);

        if (f)
            return {x, y};
    }
    return {-1, -1};
}

void solve() {
    read(n);
    for (int i = 0; i < n; ++i) {
        int x; read(x);
        ++v[x];
        ckmax(mx, x);
    }

    x = 1;
    for (; x <= n; ++x)
        if (v[x] != 4 * x)
            break;

    for (int i = 1; i * i <= n; ++i) {
        if (n % i)
            continue;

        pair<int, int> ret = go(i, n / i);
        if (~ret.first) {
            print(i, n / i);
            print(ret);
            return;
        }
        ret = go(n / i, i);
        if (~ret.first) {
            print(n / i, i);
            print(ret);
            return;
        }
    }

    print(-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
    solve();
}
