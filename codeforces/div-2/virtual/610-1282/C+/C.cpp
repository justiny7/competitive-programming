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

void solve() {
    int n;
    ll T, a, b, ztot = 0, otot = 0;
    read(n, T, a, b);
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; ++i) {
        read(v[i].second);
        if (v[i].second)
            ++otot;
        else
            ++ztot;
    }
    for (int i = 0; i < n; ++i)
        read(v[i].first);
    //print("!!");
    //for (auto i : v)
    //print(i);
    sort(all(v));
    ll ans = 0, need = 0;
    if (v[0].first > 0) {
        ll tot = v[0].first - 1;
        ll take = min(ztot, tot / a);
        ans += take;
        tot -= take * a;
        take = min(otot, tot / b);
        ans += take;
    }
    for (int i = 0; i < n; ++i) {
        ll here = i + 1;
        need += (v[i].second ? b : a);
        ztot -= (v[i].second == 0);
        otot -= (v[i].second == 1);
        if (i < n - 1 && v[i + 1].first == v[i].first)
            continue;
        ll tot = (i == n - 1 ? T : v[i + 1].first - 1);
        tot -= need;
        if (tot < 0)
            continue;
        ll take = min(ztot, tot / a);
        here += take;
        tot -= take * a;
        take = min(otot, tot / b);
        here += take;
        //print(i, here);
        ckmax(ans, here);
    }
    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
}
