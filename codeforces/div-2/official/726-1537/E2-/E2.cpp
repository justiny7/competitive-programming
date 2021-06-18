#include <bits/stdc++.h>
using namespace std;

//TEMPLATE {{{

//Macros
#define all(x) (x).begin(), (x).end()
#define finish(...) return void(print(__VA_ARGS__))

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
template<class T> bool ckmin(T &a, const T b) { return (b < a) ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T b) { return (a < b) ? a = b, 1 : 0; }

using ll = long long;

//Constants
const ll M = 1e9 + 7; //998244353;
const int dr[] = {1, 0, -1, 0}, dc[] = {0, 1, 0, -1};

//}}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Hash {{{
#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5e5 + 69; //or whatever N
const ll M1 = 1e9 + 7, M2 = 1e9 + 9, B = uid(501, M - 2);
ll p1[N], p2[N], inv1[N], inv2[N];

ll binpow(ll a, ll b, ll MOD) {
    ll ret = 1;
    while (b) {
        if (b & 1)
            (ret *= a) %= MOD;
        (a *= a) %= MOD, b >>= 1;
    }
    return ret;
}
void prep() {
    p1[0] = p2[0] = inv1[0] = inv2[0] = 1;
    for (int i = 1; i < N; ++i) {
        p1[i] = p1[i - 1] * B % M1;
        p2[i] = p2[i - 1] * B % M2;
        inv1[i] = binpow(p1[i], M1 - 2, M1);
        inv2[i] = binpow(p2[i], M2 - 2, M2);
    }
}

struct Hash {
    vector<ll> hsh1, hsh2;
    Hash() {}
    Hash(string s) { init(s); }

    void init(string s) {
        int sz = s.size();
        hsh1.resize(sz + 1), hsh2.resize(sz + 1);
        for (int i = 0; i < sz; ++i) {
            hsh1[i + 1] = (hsh1[i] + s[i] * p1[i]) % M1;
            hsh2[i + 1] = (hsh2[i] + s[i] * p2[i]) % M2;
        }
    }
    pair<ll, ll> get(int st, int len) {
        int en = st + len;
        ll ret1 = (((hsh1[en] - hsh1[st]) * inv1[st] % M1) + M1) % M1,
           ret2 = (((hsh2[en] - hsh2[st]) * inv2[st] % M2) + M2) % M2;
        return {ret1, ret2};
    }
};
// }}}

int n, k;
Hash h;
string s;

bool ok(int x) {
    //print("testing", x);
    int lo = 0, hi = min(x + 1, n - x);

    while (lo < hi) {
        int m = lo + hi + 1 >> 1;
        //print(lo, m, hi);
        //print(s.substr(0, m), s.substr(x + 1, m));
        //print(h.get(0, m), h.get(x + 1, m));

        if (h.get(0, m) == h.get(x + 1, m))
            lo = m;
        else
            hi = m - 1;
    }

    //print(">", lo, s[lo], s[x + lo + 1]);

    return (lo != min(x + 1, n - x) && s[lo] < s[x + lo + 1]);
}

void solve() {
    read(n, k, s);
    h.init(s);

    int c = 0;
    for (; c < n - 1; ++c)
        if (ok(c))
            break;

    ++c;
    for (int i = 0; i < k; ++i)
        write(s[i % c]);
    print();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    prep();

    //int t; read(t);
    //while (t--)
    solve();
}
