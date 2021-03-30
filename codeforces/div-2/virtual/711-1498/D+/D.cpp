#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//{{{ TEMPLATE

//Macros
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define finish(...) return void(print(__VA_ARGS__))
#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)

#define IN(i, x) for (auto &(i) : (x))
#define FIT(i, x) for (auto (i) = (x).begin(); (i) != (x).end(); ++(i))
#define RIT(i, x) for (auto (i) = (x).rbegin(); (i) != (x).rend(); ++(i))

//Input
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { IN(i, a) read(i); }

template<class T> void read(vector<T> &v) { IN(i, v) read(i); }
template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

//Output
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; IN(i, a) o << s << i, s = " "; return o; }

template<class H, class T> ostream &operator<<(ostream &o, vector<pair<H, T>> &v) { string s; IN(i, v) o << s << i, s = "\n"; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, vector<array<T, S>> &v) { string s; IN(i, v) o << s << i, s = "\n"; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; IN(i, v) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<vector<T>> &v) { string s; IN(i, v) o << s << i, s = "\n"; return o; }

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

const int mxN = 201, mxM = 1e5 + 1;
int n, m, dp[mxM];

ll get(ll j, ll x) {
    ll ret = j;
    ret *= x;
    ret = (ret + 99999) / 100000;
    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    read(n, m);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        ll t, x, y;
        read(t, x, y);
        vector<int> lst(m + 1, -1);
        if (t & 1) {
            x = (x + 99999) / 100000;
            for (int j = 0; j <= m; ++j) {
                if (~dp[j])
                    lst[j] = 0;
                else if (j - x >= 0 && ~lst[j - x])
                    lst[j] = lst[j - x] + 1;
                if (~lst[j] && lst[j] <= y && dp[j] < 0)
                    dp[j] = i + 1;
            }
        }
        else {
            for (int j = 0; j <= m; ++j) {
                if (~dp[j])
                    lst[j] = 0;
                if (~lst[j]) {
                    ll nxt = get(j, x);
                    if (nxt >= 0 && nxt <= m)
                        lst[nxt] = lst[j] + 1;
                }
                if (~lst[j] && lst[j] <= y && dp[j] < 0)
                    dp[j] = i + 1;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
        write(dp[i], " \n"[i == m]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //int t; read(t);
    //while (t--)
    solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
}
