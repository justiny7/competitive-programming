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

const int MOD = 998'244'353;
using Mint = mi<MOD>;

const int N = 2e5 + 69;
int n, q;
Mint ans, den[N], num[N];
set<int> cur;

// for range [L, R] where L is checkpoint:
// ev[L] = 1 / p[R] + 1 / (p[R - 1] * p[R]) + 1 / (p[R - 2] * p[R - 1] * p[R]) + ... + 1 / (p[L] * ... * p[R])
//       = (1 + p[L] + (p[L] * p[L + 1]) + ... + (p[L] * ... * p[R - 1])) / (p[L] * ... * p[R])
//
// den[i] = p[1] * p[2] * ... * p[i]
// num[i] = den[1] + den[2] + ... + den[i]

// [L, R)
Mint ev_range(int l, int r) {
    Mint tp = ((num[r - 2] - num[l - 1]) / den[l - 1]) + 1;
    Mint bt = den[r - 1] / den[l - 1];
    return tp / bt;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;

    den[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;

        den[i] = Mint(x) / 100;
        den[i] *= den[i - 1];
        num[i] = den[i] + num[i - 1];
    }

    ans = ev_range(1, n + 1);

    cur.insert(1);
    cur.insert(n + 1);

    while (q--) {
        int x;
        cin >> x;

        int lo = *prev(cur.lower_bound(x)), hi = *cur.upper_bound(x);
        if (cur.count(x)) {
            ans -= ev_range(lo, x);
            ans -= ev_range(x, hi);
            ans += ev_range(lo, hi);
            cur.erase(x);
        } else {
            ans -= ev_range(lo, hi);
            ans += ev_range(lo, x);
            ans += ev_range(x, hi);
            cur.insert(x);
        }

        cout << ans << '\n';
    }
}

