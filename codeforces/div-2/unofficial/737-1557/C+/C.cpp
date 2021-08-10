#include <bits/stdc++.h>
using namespace std;

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

void solve() {
    int n, k;
    cin >> n >> k;

    if (n & 1)
        cout << binpow(binpow(Mint(2), n - 1) + 1, k) << '\n';
    else {
        Mint ans;
        for (int i = 0; i <= k; ++i) {
            Mint here = 1;

            // make prefix same
            if (i > 0)
                here *= binpow(binpow(Mint(2), n - 1) - 1, i);

            // make this one greater
            here *= 1;

            // fill in the rest
            if (i <= k - 1) {
                long long left = 1LL * (k - 1 - i) * n;
                here *= binpow(Mint(2), left);
            }

            ans += here;
        }

        cout << ans << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

