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

const int N = 69, M = 1e5 + 69;
int n, m, l[N], r[N];
Mint ans, dp[N][M];

// Math {{{
int spf[M], u[M];
vector<int> facts[M];
void sieve() {
    for (long long i = 2; i < M; ++i) {
        if (!spf[i]) {
            spf[i] = i;
            for (long long j = i * i; j < M; j += i)
                if (!spf[j])
                    spf[j] = i;
        }
    }
}
void mobius() {
    for (int i = 1; i < M; ++i) {
        for (int j = i; j < M; j += i)
            facts[j].push_back(i);

        int cur = i, c = 0;
        while (cur > 1) {
            int nxt = cur / spf[cur];
            if (spf[nxt] == spf[cur])
                break;
            ++c;
            cur = nxt;
        }

        if (cur == 1)
            u[i] = (c & 1) ? -1 : 1;
    }
}
// }}}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    sieve(); mobius();

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
        cin >> l[i] >> r[i];

    for (int x = 1; x <= m; ++x) {
        int mx = m / x;

        // base case
        for (int i = 0; i <= mx; ++i)
            dp[0][i] = 0;
        dp[0][0] = 1;

        bool f = 0;
        for (int i = 1; i <= n; ++i) {
            int lf = (l[i] + x - 1) / x, rt = r[i] / x;
            if (lf > rt) {
                f = 1;
                break;
            }

            vector<Mint> pref(mx + 69);
            for (int j = 0; j <= mx; ++j)
                pref[j] += (j ? pref[j - 1] : 0) + dp[i - 1][j];
            for (int j = 0; j <= mx; ++j) {
                dp[i][j] = 0;
                if (j >= lf)
                    dp[i][j] += pref[j - lf];
                if (j >= rt + 1)
                    dp[i][j] -= pref[j - (rt + 1)];
            }
        }

        if (f)
            continue;

        Mint here;
        for (int i = 0; i <= mx; ++i)
            here += dp[n][i];

        ans += here * u[x];
    }

    cout << ans << '\n';
}

