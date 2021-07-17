#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Modular Int {{{
template<int MD> struct mi {
    int v;
    explicit operator int() const { return v; }

    mi(long long _v = 0) {
        v = (-MD <= _v && _v < MD) ? _v : _v % MD;
        v = (v < 0) ? v + MD : v;
    }

    friend bool operator==(const mi &a, const mi &b) { return a.v == b.v; }
    friend bool operator!=(const mi &a, const mi &b) { return !(a == b); }
    friend bool operator<(const mi &a, const mi &b) { return a.v < b.v; }

    mi &operator+=(const mi &o) { if ((v += o.v) >= MD) v -= MD; return *this; }
    mi &operator-=(const mi &o) { if ((v -= o.v) < 0) v += MD; return *this; }
    mi &operator*=(const mi &o) { v = 1LL * v * o.v % MD; return *this; }
    mi &operator/=(const mi &o) { return (*this) *= inv(o); }

    friend mi inv(const mi &m) { return binpow(m, MD - 2); }
    friend mi binpow(mi b, long long e) {
        mi ret = 1;
        for (; e; e >>= 1, b *= b)
            if (e & 1)
                ret *= b;
        return ret;
    }

    friend mi operator+(mi a, const mi &b) { return a += b; }
    friend mi operator-(mi a, const mi &b) { return a -= b; }
    friend mi operator*(mi a, const mi &b) { return a *= b; }
    friend mi operator/(mi a, const mi &b) { return a /= b; }

    friend istream &operator>>(istream &i, mi &m) { long long x; i >> x; m.v = x; return i; }
    friend ostream &operator<<(ostream &o, const mi &m) { o << m.v; return o; }
};
// }}}

const int MOD = 1e9 + 7;
using Mint = mi<MOD>;

const int N = 2e5 + 69;
Mint fact[N];

Mint nCr(ll n, ll r) {
    if (r < 0 || n < r)
        return 0;
    return fact[n] / (fact[r] * fact[n - r]);
}

int n, t[N];
ll mx;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i;

    cin >> n >> mx;

    Mint ans, p = 1, sum = 1;
    for (int i = 0; i < n; ++i) {
        sum = 2 * sum - nCr(i, mx);
        ll need; cin >> need;

        if (mx > i + 1) {
            ll sub = min(mx - (i + 1), need);
            mx -= sub, need -= sub;
        }

        ll rem = min(mx + 1, need);
        for (int j = 0; j < rem; ++j)
            sum -= nCr(i + 1, mx - j);
        mx -= rem;

        p /= 2;
        ans += p * sum;
    }

    cout << ans << '\n';
}
