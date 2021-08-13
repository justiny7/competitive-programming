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

const int N = 2e3 + 69;
int n, cnt[N];
string s;
Mint dp[N][N], p[N];
bool vis[N][N];

Mint go(int l = 0, int r = n - 1) {
    if (l >= r || vis[l][r])
        return dp[l][r];

    vis[l][r] = 1;
    if (s[l] != '(')
        dp[l][r] += go(l + 1, r);
    if (s[r] != ')')
        dp[l][r] += go(l, r - 1);
    if (s[l] != '(' && s[r] != ')')
        dp[l][r] -= go(l + 1, r - 1);
    if (s[l] != ')' && s[r] != '(')
        dp[l][r] += go(l + 1, r - 1) + p[cnt[r - 1] - cnt[l]];

    return dp[l][r];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> s, n = s.size();

    for (int i = 0; i < n; ++i) {
        cnt[i] += s[i] == '?';
        if (i > 0)
            cnt[i] += cnt[i - 1];
    }

    p[0] = 1;
    for (int i = 1; i < N; ++i)
        p[i] = p[i - 1] * 2;

    cout << go() << '\n';
}

