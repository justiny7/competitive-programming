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

const int N = (1 << 15) + 69; // or whatever N
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
    Hash(vector<int> s) { init(s); }

    void init(vector<int> s) {
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
    int n; read(n);
    vector<int> a(n);
    read(a);

    map<array<ll, 2>, int> mp;

    for (int i = 0; i < (1 << 15); ++i) {
        vector<int> res(n);
        for (int j = 0; j < n; ++j) {
            int x = a[j] ^ i;
            for (int k = 0; k < 15; ++k)
                res[j] += (x >> k & 1);
        }

        int mx = *max_element(all(res));
        for (int j = mx; j <= 15; ++j) {
            vector<int> inv(n);
            for (int k = 0; k < n; ++k)
                inv[k] = j - res[k];

            Hash h(inv);
            mp[h.get(0, n)] = i;
        }
    }

    for (int i = 0; i < (1 << 15); ++i) {
        vector<int> res(n);
        for (int j = 0; j < n; ++j) {
            int x = a[j] ^ (i << 15);
            for (int k = 15; k < 30; ++k)
                res[j] += (x >> k & 1);
        }

        Hash h(res);
        auto here = h.get(0, n);
        if (mp.count(here))
            finish(mp[here] | (i << 15));
    }

    print(-1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    prep();

    //int t; read(t);
    //while (t--)
    solve();
}
