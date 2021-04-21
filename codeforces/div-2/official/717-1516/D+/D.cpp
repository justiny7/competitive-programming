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

const int N = 1e5 + 69, L = 19;
int n, q, a[N], nxt[N], lift[N][L], dep[N];
vector<int> radj[N];
map<int, int> lst;

int spf[N];
void sieve() {
    for (int i = 2; i < N; i += 2)
        spf[i] = 2;
    for (int i = 1; i < N; i += 2)
        spf[i] = i;
    for (long long i = 3; i < N; i += 2) {
        if (spf[i] == i)
            for (long long j = i * i; j < N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
    }
}
void dfs(int v, int p = n + 1, int d = 0) {
    dep[v] = d, lift[v][0] = p;
    for (int i = 1; i < L; ++i)
        lift[v][i] = lift[lift[v][i - 1]][i - 1];
    for (int u : radj[v])
        if (u != p)
            dfs(u, v, d + 1);
}

int jump(int v, int k) {
    if (k > dep[v])
        return n + 1;
    int ret = v;
    for (int i = L - 1; ~i; --i)
        if (k & (1 << i))
            ret = lift[ret][i];
    return ret;
}

void solve() {
    read(n, q);
    for (int i = 1; i <= n; ++i)
        read(a[i]);
    nxt[n + 1] = n + 1;
    for (int i = n; i; --i) {
        int to = nxt[i + 1], x = a[i];
        while (x > 1) {
            int k = spf[x];
            if (lst.count(k))
                ckmin(to, lst[k]);
            lst[k] = i;
            while (x % k == 0)
                x /= k;
        }
        nxt[i] = to;
        radj[to].push_back(i);
    }
    for (int i = n; ~i; --i)
        if (nxt[i] == n + 1)
            dfs(i);
    //for (int i = 1; i <= n; ++i)
    //print(i, nxt[i], dep[i]);
    while (q--) {
        int l, r;
        read(l, r);
        int lo = 0, hi = n;
        while (lo < hi) {
            int m = lo + hi >> 1;
            //print(">", l, m, jump(l, m));
            if (jump(l, m) >= r)
                hi = m;
            else
                lo = m + 1;
        }
        print(lo + (jump(l, lo) == r));
    }
}

int main() {
    sieve();
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
    solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
}
