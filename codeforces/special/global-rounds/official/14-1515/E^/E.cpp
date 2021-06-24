#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Mint {{{
int M;
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
//}}}

const int N = 469;
int n;
Mint ans, fact[N], ifact[N], dp[N][N], p[N], nCr[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> M;

    fact[0] = ifact[0] = p[0] = 1;
    for (int i = 1; i < N; ++i) {
        fact[i] = fact[i - 1] * Mint(i);
        ifact[i] = Mint(1) / fact[i];
        p[i] = p[i - 1] * Mint(2);
    }

    for (int i = 0; i < N; ++i)
        for (int j = 0; j <= i; ++j)
            nCr[i][j] = fact[i] * ifact[j] * ifact[i - j];

    dp[0][0] = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= i; ++j)
            for (int k = 1; k <= n - i; ++k)
                dp[i + k + 1][j + k] += dp[i][j] * p[k - 1] * nCr[j + k][k];

    for (int i = 0; i <= n; ++i)
        ans += dp[n + 1][i];

    cout << ans << '\n';
}
