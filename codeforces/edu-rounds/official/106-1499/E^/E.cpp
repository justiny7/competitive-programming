#include <bits/stdc++.h>
using namespace std;

//{{{ Mint 
const int M = 998'244'353;
struct Mint {
    int val;
    Mint (int _val = 0) : val(_val) {
        val=(-M <= val && val < M) ? val : val % M;
        if (val < 0)
            val += M;
    }
    explicit operator int() const { return val; }
    friend bool operator==(const Mint &a, const Mint &b) { return a.val == b.val; }
    friend bool operator!=(const Mint &a, const Mint &b) { return !(a == b); }
    friend bool operator<(const Mint &a, const Mint &b) { return a.val < b.val; }

    Mint &operator+=(const Mint &o) { if ((val += o.val) >= M) val -= M; return *this; }
    Mint &operator-=(const Mint &o) { if ((val -= o.val) < 0) val += M; return *this; }
    Mint &operator*=(const Mint &o) { val=static_cast<int>(static_cast<long long>(val) * o.val % M); return *this; }
    Mint &operator/=(const Mint &o) { return (*this) *= inv(o); }

    friend Mint binpow(Mint a, int b) {
        Mint ret(1);
        for (; b; b >>= 1, a *= a) if (b & 1) ret *= a;
        return ret;
    }
    friend Mint inv(const Mint &a) { return binpow(a, M-2); }

    Mint operator-() { return Mint(-val); }
    Mint operator++() { return (*this) += 1; }
    Mint operator--() { return (*this) -= 1; }
    friend Mint operator+(Mint a, const Mint &b) { return a += b; }
    friend Mint operator-(Mint a, const Mint &b) { return a -= b; }
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }
    friend Mint operator/(Mint a, const Mint &b) { return a /= b; }

    friend ostream &operator<<(ostream &o, const Mint &m) { o << m.val; return o; }
    friend istream &operator>>(istream &i, Mint &m) { int x; i >> x; m.val = x; return i; }
};
//}}}

const int MX = 1e3 + 1;
int n, m, lst[2][MX]; 
string s, t;
Mint ans, dp[MX][MX][2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> t;
    n = s.size(), m = t.size();
    lst[0][0] = lst[1][0] = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] ^ s[i - 1])
            lst[0][i] = lst[0][i - 1] + 1;
        else
            lst[0][i] = 1;
    }
    for (int i = 1; i < m; ++i) {
        if (t[i] ^ t[i - 1])
            lst[1][i] = lst[1][i - 1] + 1;
        else
            lst[1][i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i && s[i] ^ s[i - 1])
                dp[i][j][0] += dp[i - 1][j][0];
            if (j && t[j] ^ t[j - 1])
                dp[i][j][1] += dp[i][j - 1][1];
            if (s[i] ^ t[j]) {
                dp[i][j][0] += lst[1][j] + (i ? dp[i - 1][j][1] : 0);
                dp[i][j][1] += lst[0][i] + (j ? dp[i][j - 1][0] : 0);
            }
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans += dp[i][j][0] + dp[i][j][1];
    cout << ans << '\n';
}

