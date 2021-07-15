#include <bits/stdc++.h>
using namespace std;

// TEMPLATE {{{

/* Macros */
#define all(x) (x).begin(), (x).end()
#define finish(...) return void(print(__VA_ARGS__))

/* Input */
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { for (T &i : a) read(i); }
template<class T> void read(vector<T> &v) { for (T &i : v) read(i); }

template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

/* Output */
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; for (T i : a) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T i : v) o << s << i, s = " "; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

/* Misc */
template<class T> bool ckmin(T &a, const T b) { return (b < a) ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T b) { return (a < b) ? a = b, 1 : 0; }

using ll = long long;

// }}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Poly Hash {{{
#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 5e5 + 69; // or whatever N
const ll MD[2] = {(ll)1e9 + 7, (ll)1e9 + 9}, B = uid(501, MD[0] - 2);
ll p[2][N], inv[2][N];

ll binpow(ll b, ll e, int MOD) {
    ll ret = 1;
    for (; e; (b *= b) %= MOD, e >>= 1)
        if (e & 1)
            (ret *= b) %= MOD;
    return ret;
}

// Call prep() before creating any hashes
void prep() {
    for (int c = 0; c < 2; ++c) {
        p[c][0] = inv[c][0] = 1;
        for (int i = 1; i < N; ++i) {
            p[c][i] = p[c][i - 1] * B % MD[c];
            inv[c][i] = binpow(p[c][i], MD[c] - 2, MD[c]);
        }
    }
}

struct Hash {
    vector<ll> hsh[2];
    Hash() {}
    Hash(string s) { init(s); }

    void init(string s) {
        int sz = s.size();
        for (int c = 0; c < 2; ++c) {
            hsh[c].resize(sz + 1);
            for (int i = 0; i < sz; ++i)
                hsh[c][i + 1] = (hsh[c][i] + s[i] * p[c][i]) % MD[c];
        }
    }
    array<ll, 2> get(int st, int len) {
        array<ll, 2> ret;
        for (int c = 0; c < 2; ++c)
            ret[c] = (((hsh[c][st + len] - hsh[c][st]) * inv[c][st] % MD[c]) + MD[c]) % MD[c];
        return ret;
    }
};
// }}}

void solve() {
    string s, t;
    read(s, t);

    int n = s.size(), m = t.size();

    Hash h(t);
    int sz = 0;
    for (int i = 1; i < m; ++i) {
        if (h.get(0, i) == h.get(m - i, i))
            sz = i;
    }

    //print(sz);

    vector<int> have(2), need(2);
    for (char c : s)
        ++have[c - '0'];

    string ans;
    int ind = 0;
    while (1) {
        if (t[ind] == '0') {
            if (!have[0])
                break;
            ans += '0';
            --have[0];
        }
        else {
            if (!have[1])
                break;;
            ans += '1';
            --have[1];
        }

        ind = (ind + 1 < m ? ind + 1 : sz);
    }

    while (have[0]--)
        ans += '0';
    while (have[1]--)
        ans += '1';

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    prep();

    //int t; read(t);
    //while (t--)
    solve();
}
