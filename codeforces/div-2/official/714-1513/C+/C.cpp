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

//{{{ Mint
struct Mint {
    int val;
    Mint (int _val = 0) : val(_val) {
        val = (-M <= val && val < M) ? val : val % M;
        if (val < 0)
            val += M;
    }
    explicit operator int() const { return val; }
    friend bool operator==(const Mint &a, const Mint &b) { return a.val == b.val; }
    friend bool operator!=(const Mint &a, const Mint &b) { return !(a == b); }
    friend bool operator<(const Mint &a, const Mint &b) { return a.val < b.val; }

    Mint &operator+=(const Mint &o) { if ((val += o.val) >= M) val -= M; return *this; }
    Mint &operator-=(const Mint &o) { if ((val -= o.val) < 0) val += M; return *this; }
    Mint &operator*=(const Mint &o) { val = static_cast<int>(static_cast<long long>(val) * o.val % M); return *this; }
    Mint &operator/=(const Mint &o) { return (*this) *= inv(o); }

    friend Mint binpow(Mint a, int b) {
        Mint ret(1);
        for (; b; b >>= 1, a *= a)
            if (b & 1)
                ret *= a;
        return ret;
    }
    friend Mint inv(const Mint &a) { return binpow(a, M - 2); }

    Mint operator-() { return Mint(-val); }
    Mint operator++() { return (*this) += 1; }
    Mint operator--() { return (*this) -= 1; }
    friend Mint operator+(Mint a, const Mint &b) { return a += b; }
    friend Mint operator-(Mint a, const Mint &b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint &b) { return a /= b; }

    friend ostream &operator<<(ostream &o, const Mint &m) { o << m.val; return o; }
    friend istream &operator>>(istream &i, Mint &m) { int x; i >> x; m.val = x; return i; }
};
//}}}

const int MX = 2e5 + 69;
Mint cnt[MX], c[MX][10];

void solve() {
    ll n, m;
    read(n, m);
    Mint ans = 0;
    while (n > 0) {
        ll x = n % 10;
        n /= 10;
        ans += cnt[m + x];
    }
    print(ans);
}

int main() {
    c[0][0] = 1;
    for (int i = 0; i < MX; ++i) {
        for (int j = 0; j < 10; ++j)
            cnt[i] += c[i][j];
        if (i == MX - 1)
            continue;
        for (int j = 0; j < 9; ++j)
            c[i + 1][j + 1] += c[i][j];
        c[i + 1][0] += c[i][9];
        c[i + 1][1] += c[i][9];
    }
    cin.tie(0)->sync_with_stdio(0);
    int t; read(t);
    while (t--)
        solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
}
