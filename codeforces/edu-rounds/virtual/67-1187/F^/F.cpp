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

const int N = 2e5 + 69;
int n, l[N], r[N];
Mint ans, psum, p[N], dif[N];

Mint calc(int i) {
    Mint ret;
    if (i > 0) {
        Mint inter = max(0, min({r[i - 1], r[i], r[i + 1]}) - max({l[i - 1], l[i], l[i + 1]}));
        ret = inter / (dif[i - 1] * dif[i] * dif[i + 1]);
    }

    return p[i] + p[i + 1] - 1 + ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> l[i];
    for (int i = 0; i < n; ++i)
        cin >> r[i], dif[i] = ++r[i] - l[i];

    p[0] = psum = 1;
    for (int i = 1; i < n; ++i) {
        Mint inter = max(0, min(r[i - 1], r[i]) - max(l[i - 1], l[i]));
        p[i] = 1 - (inter / (dif[i - 1] * dif[i]));
        psum += p[i];
    }

    for (int i = 0; i < n; ++i) {
        Mint here = psum;

        for (int j = max(0, i - 1); j <= min(n - 1, i + 1); ++j)
            here -= p[j];

        // i == j
        ans += p[i];
        // |i - j| > 1
        ans += p[i] * here;

        // |i - j| = 1
        if (i > 0)
            ans += calc(i - 1);
        if (i < n - 1)
            ans += calc(i);
    }

    cout << ans << '\n';
}
