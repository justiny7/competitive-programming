#include <bits/stdc++.h>
using namespace std;

// Modular Int {{{
template<int MD> struct mi {
    int v;
    explicit operator int() const { return v; }
    mi(long long _v = 0) {
        v = (-MD <= _v && _v < MD) ? _v : _v % MD;
        if (v < 0) v += MD;
    }

    mi &operator+=(const mi &o) { if ((v += o.v) >= MD) v -= MD; return *this; }
    mi &operator-=(const mi &o) { if ((v -= o.v) < 0) v += MD; return *this; }
    mi &operator*=(const mi &o) { v = 1LL * v * o.v % MD; return *this; }
    mi &operator/=(const mi &o) { return (*this) *= inv(o); }

    friend mi operator+(mi a, const mi &b) { return a += b; }
    friend mi operator-(mi a, const mi &b) { return a -= b; }
    friend mi operator*(mi a, const mi &b) { return a *= b; }
    friend mi operator/(mi a, const mi &b) { return a /= b; }

    friend mi inv(const mi &m) { return binpow(m, MD - 2); }
    friend mi binpow(mi b, long long e) {
        mi ret = 1;
        for (; e; e >>= 1, b *= b) if (e & 1) ret *= b;
        return ret;
    }

    friend bool operator==(const mi &a, const mi &b) { return a.v == b.v; }
    friend bool operator!=(const mi &a, const mi &b) { return !(a == b); }
    friend bool operator<(const mi &a, const mi &b) { return a.v < b.v; }

    friend istream &operator>>(istream &i, mi &m) { long long x; i >> x; m.v = x; return i; }
    friend ostream &operator<<(ostream &o, const mi &m) { o << m.v; return o; }
};
// }}}

const int N = 1e6 + 69; // or whatever N
const int MOD = 998'244'353;
using Mint = mi<MOD>;

// Poly hash {{{
using ll = long long;

#define uid(a, b) uniform_int_distribution<int>((a), (b))(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll MD[2] = {(ll)1e9 + 7, (ll)1e9 + 9}, B = uid(501, MD[0] - 2);
ll p[2][N];

// Call prep() before creating any hashes
void prep() {
    for (int c = 0; c < 2; ++c) {
        p[c][0] = 1;
        for (int i = 1; i < N; ++i)
            p[c][i] = p[c][i - 1] * B % MD[c];
    }
}

struct Hash {
    vector<ll> hsh[2];

    void init(string s) {
        int sz = s.size();
        for (int c = 0; c < 2; ++c) {
            hsh[c].resize(sz + 1);
            for (int i = 0; i < sz; ++i)
                hsh[c][i + 1] = (hsh[c][i] * B + s[i]) % MD[c];
        }
    }
    array<ll, 2> get(int st, int len) {
        array<ll, 2> ret;
        for (int c = 0; c < 2; ++c)
            ret[c] = (hsh[c][st + len] - hsh[c][st] * p[c][len] % MD[c] + MD[c]) % MD[c];
        return ret;
    }
};
// }}}

// BIT {{{
template<class T> struct BIT {
    int sz;
    vector<T> bit;

    void init(int _sz) {
        sz = _sz;
        bit.resize(sz, 0);
    }
    void upd(int i, T x) {
        for (++i; i < sz; i += i & -i)
            bit[i] += x;
    }
    T query(int i) {
        T ret = 0;
        for (++i; i; i -= i & -i)
            ret += bit[i];
        return ret;
    }
    T query(int l, int r) {
        return query(r) - query(l - 1);
    }
};
// }}}

int n;
string s, l, r;
Hash hs, hl, hr;
BIT<Mint> dp;
bool l_is_zero;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    prep();

    cin >> s >> l >> r, n = s.size();
    hs.init(s);
    hl.init(l);
    hr.init(r);
    dp.init(n + 69);

    l_is_zero = l == "0";

    dp.upd(n, 1);
    for (int i = n - 1; ~i; --i) {
        if (l.size() > n - i)
            continue;
        if (s[i] == '0') {
            if (l_is_zero)
                dp.upd(i, dp.query(i + 1, i + 1));
            continue;
        }

        // ql = min pos that works, qr = max pos that works
        bool extend_l = 0;
        { // compare substring [i, ql] to l - if [i, ql] is smaller, extend ql by 1
            int lo = 0, hi = l.size();
            while (lo < hi) {
                int m = lo + hi + 1 >> 1;
                if (hl.get(0, m) == hs.get(i, m))
                    lo = m;
                else
                    hi = m - 1;
            }

            if (lo < l.size() && l[lo] > s[i + lo])
                extend_l = 1;
        }

        if (extend_l && i == n - 1)
            continue;

        int ql = i + l.size() - 1 + extend_l;

        bool retract_r = 0;
        if (r.size() <= n - i) {
            int lo = 0, hi = r.size();
            while (lo < hi) {
                int m = lo + hi + 1 >> 1;
                if (hr.get(0, m) == hs.get(i, m))
                    lo = m;
                else
                    hi = m - 1;
            }

            if (lo < r.size() && r[lo] < s[i + lo])
                retract_r = 1;
        }

        int qr = i + min((int)r.size(), n - i) - 1 - retract_r;

        // assert(ql <= qr);
        if (ql <= qr)
            dp.upd(i, dp.query(ql + 1, qr + 1));

        // cout << i << " " << extend_l << " " << retract_r << '\n';
        // cout << i << " " << ql << " " << qr << " " << dp.query(i, i) << '\n';
    }

    cout << dp.query(0) << '\n';
}

