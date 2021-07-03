#include <bits/stdc++.h>
using namespace std;

// Mint {{{
const int M = 998244353;
struct Mint {
    int val;
    Mint (long long _val = 0) {
        val = (-M <= _val && _val < M) ? _val : _val % M;
        if (val < 0)
            val += M;
    }
    explicit operator int() const { return val; }
    friend bool operator==(const Mint &a, const Mint &b) { return a.val == b.val; }
    friend bool operator!=(const Mint &a, const Mint &b) { return !(a == b); }
    friend bool operator<(const Mint &a, const Mint &b) { return a.val < b.val; }

    Mint &operator+=(const Mint &o) { if ((val += o.val) >= M) val -= M; return *this; }
    Mint &operator-=(const Mint &o) { if ((val -= o.val) < 0) val += M; return *this; }
    Mint &operator*=(const Mint &o) { val = static_cast<int>(static_cast<long long>(val) * o.val % M); return *this; }
    Mint &operator/=(const Mint &o) { return (*this) *= inv(o); }

    friend Mint binpow(Mint b, long long e) {
        Mint ret(1);
        for (; e; e >>= 1, b *= b)
            if (e & 1)
                ret *= b;
        return ret;
    }
    friend Mint inv(const Mint &a) { return binpow(a, M - 2); }

    Mint operator-() { return Mint(-val); }
    Mint operator++() { return (*this) += 1; }
    Mint operator--() { return (*this) -= 1; }
    friend Mint operator+(Mint a, const Mint &b) { return a += b; }
    friend Mint operator-(Mint a, const Mint &b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint &b) { return a /= b; }

    friend ostream &operator<<(ostream &o, const Mint &m) { o << m.val; return o; }
    friend istream &operator>>(istream &i, Mint &m) { long long x; i >> x; m.val = x; return i; }
};
// }}}

const int N = 569;
int n, a[N];
Mint ans, dp[N][N]; // dp[i][j] = # of subsequences ending at i with j numbers <= a[t] for some t

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        char c; cin >> c;
        if (c == '+')
            cin >> a[i];
    }

    for (int t = 0; t < n; ++t) { // contribution of element t
        if (!a[t])
            continue;

        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                dp[i][j] = 0;

        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= n; ++j) // don't take element i
                dp[i + 1][j] = dp[i][j];

            if (i == t)
                continue;

            for (int j = 0; j <= n; ++j) {
                if (a[i] == 0) { // remove smallest element
                    if (j < n)
                        dp[i + 1][j] += dp[i][j + 1];
                    if (i < t && j == 0)
                        dp[i + 1][j] += dp[i][j];
                }
                else if (a[i] < a[t] || (i < t && a[i] == a[t])) // add smaller element
                    dp[i + 1][j] += (j > 0) ? dp[i][j - 1] : 0;
                else // add larger element
                    dp[i + 1][j] += dp[i][j];
            }
        }

        for (int i = 0; i <= n; ++i)
            ans += dp[n][i] * a[t];
    }

    cout << ans << '\n';
}
