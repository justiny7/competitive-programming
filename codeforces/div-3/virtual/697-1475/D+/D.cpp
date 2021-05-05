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
const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve() {
    int n, m;
    read(n, m);
    vector<int> a(n), b(n);
    read(a, b);
    if (accumulate(all(a), 0LL) < m)
        finish(-1);
    vector<ll> a1, a2;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 1)
            a1.push_back(a[i]);
        else
            a2.push_back(a[i]);
    }
    sort(rall(a1));
    sort(rall(a2));
    a1.insert(a1.begin(), 0);
    a2.insert(a2.begin(), 0);
    for (int i = 1; i < a1.size(); ++i)
        a1[i] += a1[i - 1];
    for (int i = 1; i < a2.size(); ++i)
        a2[i] += a2[i - 1];
    ll ans = LLONG_MAX, cur = 0, sum = 0;
    for (int i = 0; i < a1.size(); ++i) {
        ll here = a1[i], need = m - here;
        auto it = lower_bound(all(a2), need);
        if (it == a2.end())
            continue;
        //print(i, here, need, *it, i + (it - a2.begin()) * 2);
        ckmin(ans, (ll)(i + (it - a2.begin()) * 2));
    }
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
}
