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
const ll M = 1e9 + 7; //998'244'353;
const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 5e5 + 69;
int n, m, dpw[N], dpb[N], dp[N];
vector<int> badj[N], wadj[N];

void solve() {
    memset(dpw, -1, sizeof(dpw));
    memset(dpb, -1, sizeof(dpb));
    memset(dp, -1, sizeof(dp));
    read(n, m);
    while (m--) {
        int u, v, c;
        read(u, v, c);
        if (c & 1)
            badj[v].push_back(u);
        else
            wadj[v].push_back(u);
    }
    dp[n] = dpw[n] = dpb[n] = 0;
    queue<int> q;
    q.push(n);
    while (q.size()) {
        int v = q.front(); q.pop();
        for (int u : badj[v]) {
            if (~dpb[u])
                continue;
            dpb[u] = dp[v] + 1;
            if (~dpb[u] && ~dpw[u]) {
                dp[u] = max(dpb[u], dpw[u]);
                q.push(u);
            }
        }
        for (int u : wadj[v]) {
            if (~dpw[u])
                continue;
            dpw[u] = dp[v] + 1;
            if (~dpb[u] && ~dpw[u]) {
                dp[u] = max(dpb[u], dpw[u]);
                q.push(u);
            }
        }
    }
    print(dp[1]);
    for (int i = 1; i <= n; ++i) {
        if (dpb[i] < 0)
            write(1);
        else if (dpw[i] < 0)
            write(0);
        else
            write((dpw[i] <= dpb[i]));
    }
    print();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
    solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
}
