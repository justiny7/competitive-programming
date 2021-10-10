#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int get(string col) {
    if (col == "white")
        return 0;
    else if (col == "red")
        return 1;
    else if (col == "blue")
        return 2;
    else if (col == "yellow")
        return 3;
    else if (col == "orange")
        return 4;
    else
        return 5;
}

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

const int MOD = 1e9 + 7;
using Mint = mi<MOD>;

const int N = 2e3 + 69, K = 60;
int k, n;
map<ll, int> given;
map<ll, Mint> dp[6];
set<ll> touched;

Mint dfs(ll v, int col) {
    if (given.count(v) && col != given[v])
        return 0;
    if (dp[col].count(v))
        return dp[col][v];

    Mint lc = 0, rc = 0;
    for (int ncol = 0; ncol < 6; ++ncol) {
        if (ncol == col || ncol == (col + 3) % 6)
            continue;
        if (touched.count(v * 2))
            lc += dfs(v * 2, ncol);
        if (touched.count(v * 2 + 1))
            rc += dfs(v * 2 + 1, ncol);
    }

    if (!touched.count(v * 2))
        lc = 1;
    if (!touched.count(v * 2 + 1))
        rc = 1;

    return dp[col][v] = lc * rc;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> k >> n;

    ll tot = (1LL << k) - 1;
    while (n--) {
        ll pos;
        string col;
        cin >> pos >> col;

        given[pos] = get(col);
        while (pos > 0) {
            if (touched.count(pos))
                break;

            touched.insert(pos);
            --tot, pos >>= 1;
        }
    }

    /*
    for (ll i : touched)
        cout << i << " ";
    cout << '\n';
    */

    Mint ans = 0;
    for (int i = 0; i < 6; ++i)
        ans += dfs(1, i);

    ans *= binpow(Mint(4), tot);
    cout << ans << '\n';
}

