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

//Input
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { for (T &i : a) read(i); }

template<class T> void read(vector<T> &v) { for (T &i : v) read(i); }
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

//Output
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; for (T i : a) o << s << i, s = " "; return o; }

template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T>> &v) { string s; for (T i : v) o << s << i, s = "\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S>> &v) { string s; for (T i : v) o << s << i, s = "\n"; return o; }

template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T i : v) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T>> &v) { string s; for (T i : v) o << s << i, s = "\n"; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

//Misc
template<class T> bool ckmin(T &a, const T b) { return (b < a ? a = b, 1 : 0); }
template<class T> bool ckmax(T &a, const T b) { return (a < b ? a = b, 1 : 0); }

using ll = long long;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//Constants
const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int N = 5e3 + 69;
int n, m, k, mx[N];
vector<int> adj[N];
array<int, 3> a[N];

void solve() {
    read(n, m, k);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
        mx[i] = i;
        adj[i].push_back(i);
    }
    while (m--) {
        int u, v;
        read(u, v);
        adj[u].push_back(v);
        ckmax(mx[v], u);
    }
    for (int i = 1; i <= n; ++i) {
        sort(all(adj[i]), [&](int u, int v) { return a[u][2] > a[v][2]; });
        //print("!", i, mx[i]);
        //print(adj[i]);
    }
    int cur = k;
    multiset<int> have;
    for (int i = 1; i <= n; ++i) {
        while (have.size() && a[i][0] > cur) {
            have.erase(have.begin());
            ++cur;
        }
        if (a[i][0] > cur)
            finish(-1);
        cur += a[i][1];
        for (int u : adj[i]) {
            if (i != mx[u])
                continue;
            if (!cur) {
                if (have.size() && *have.begin() < a[u][2]) {
                    have.erase(have.begin());
                    have.insert(a[u][2]);
                }
                else
                    break;
            }
            else {
                --cur;
                have.insert(a[u][2]);
            }
        }
        //print(">", i, cur);
        //for (int i : have)
        //write(i, ' ');
        //print();
    }
    cout << accumulate(all(have), 0) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
    solve();
}
