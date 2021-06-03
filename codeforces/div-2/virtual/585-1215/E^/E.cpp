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

#define int long long

const int N = 4e5 + 69, P = 20;
int n, a[N], dist[P][P];
vector<int> pos[P];
ll dp[1 << P];

void solve() {
    memset(dp, 0x3f, sizeof(dp));
    read(n);
    for (int i = 0; i < n; ++i) {
        int x; read(x), --x;
        pos[x].push_back(i);
    }
    for (int i = 0; i < P; ++i)
        if (pos[i].empty())
            pos[i].push_back(n++);
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < P; ++j) {
            if (i == j)
                continue;
            int p1 = 0, p2 = 0;
            while (p1 < pos[i].size()) {
                while (p2 + 1 < pos[j].size() && pos[j][p2 + 1] < pos[i][p1])
                    ++p2;
                if (pos[j][p2] < pos[i][p1])
                    dist[i][j] += p2 + 1;
                ++p1;
            }
            //print(i + 1, j + 1, dist[i][j]);
        }
    }
    dp[0] = 0;
    for (int i = 0; i < (1 << P); ++i) {
        for (int j = 0; j < P; ++j) {
            if (i & (1 << j)) {
                int here = 0;
                for (int k = 0; k < P; ++k)
                    if (i & (1 << k))
                        here += dist[k][j];
                ckmin(dp[i], dp[(i & ~(1 << j))] + here);
            }
        }
    }
    print(dp[(1 << P) - 1]);
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
    solve();
}
