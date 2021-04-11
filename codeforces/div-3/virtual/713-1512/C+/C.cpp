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

void solve() {
    int a, b; string s;
    read(a, b, s);
    int n = a + b;
    a -= count(all(s), '0');
    b -= count(all(s), '1');
    if (a < 0 || b < 0)
        finish(-1);
    for (int i = 0; i < n / 2; ++i) {
        int o = n - i - 1;
        if (s[i] != '?' && s[o] != '?') {
            if (s[i] != s[o])
                finish(-1);
            continue;
        }
        else if (s[i] == '?' && s[o] == '?')
            continue;
        bool f = 0;
        if (s[i] == '?') {
            swap(i, o);
            f = 1;
        }
        assert(s[o] == '?' && s[i] != '?');
        if (s[i] == '0') {
            if (a == 0)
                finish(-1);
            --a, s[i] = s[o] = '0';
        }
        else {
            if (b == 0)
                finish(-1);
            --b, s[i] = s[o] = '1';
        }
        if (f)
            swap(i, o);
    }
    if ((n & 1) && s[n / 2] == '?') {
        if (a & 1)
            --a, s[n / 2] = '0';
        else if (b & 1)
            --b, s[n / 2] = '1';
        else
            finish(-1);
    }
    if ((a & 1) || (b & 1))
        finish(-1);
    for (int i = 0; i < n / 2; ++i) {
        int o = n - i - 1;
        if (s[i] == '?' && s[o] == '?') {
            if (a >= 2) {
                a -= 2;
                s[i] = s[o] = '0';
            }
            else if (b >= 2) {
                b -= 2;
                s[i] = s[o] = '1';
            }
            else
                finish(-1);
        }
    }
    assert(a == 0 && b == 0);
    print(s);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
}
