#include <bits/stdc++.h>
using namespace std;

//Mint {{{
const long long M = 998244353;
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

const int N = 501;
int n, k;
Mint ans, dp[2][N][N], cnt[N]; //dp[i][j][k] = at position i, we have j max in a row so far and k in a row currently

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    dp[0][0][0] = 1;
    for (int i = 0; i < n; ++i) {
        int a = i & 1, b = a ^ 1;
        for (int j = 0; j <= n; ++j)
            for (int l = 0; l <= n; ++l)
                dp[b][j][l] = 0;
        for (int j = 0; j <= n; ++j) {
            for (int l = 0; l <= n; ++l) {
                if (l + 1 <= n)
                    dp[b][max(j, l + 1)][l + 1] += dp[a][j][l];
                dp[b][max(j, 1)][1] += dp[a][j][l];
                //cout << "> " << i << " " << j << " " << l << " " << dp[i][j][l] << '\n';
            }
        }
    }
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= n; ++j)
            cnt[i] += dp[n & 1][i][j];
    for (int i = 1; i <= n; ++i)
        cnt[i] += cnt[i - 1];
    for (int i = 1; i <= n; ++i) {
        Mint here = cnt[i] - cnt[i - 1];
        //cout << "! " << i << " " << here << " " << k << " " << i << " " << k / i - (k % i == 0) << '\n';
        ans += here * cnt[min(n, k / i - (k % i == 0))];
    }
    ans /= 2;
    cout << ans << '\n';
}
