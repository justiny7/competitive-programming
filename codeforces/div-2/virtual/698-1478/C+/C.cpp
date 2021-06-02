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

void solve() {
    int n; read(n);
    vector<ll> a(n * 2);
    read(a);
    map<ll, int> mp;
    for (ll i : a)
        ++mp[i];
    for (auto [x, c] : mp)
        if ((c != 2) || (x & 1))
            finish("NO");
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    assert(a.size() == n);
    vector<ll> dif(n);
    for (int i = 1; i < n; ++i) {
        if ((a[i] - a[i - 1]) % (2 * i))
            finish("NO");
        dif[i] = (a[i] - a[i - 1]) / (2 * i);
        //print(i, dif[i]);
    }
    for (int i = 1; i < n; ++i)
        a[0] -= 2 * (n - i) * dif[i];
    //print(a[0]);
    if (a[0] > 0 && (a[0] % (n * 2) == 0))
        print("YES");
    else
        print("NO");
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
}
