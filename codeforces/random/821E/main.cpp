#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int C = 16;

//{{{ Mint
const ll M = 1e9 + 7;
struct Mint {
    int val;
    Mint (int _val = 0) : val(_val) {
        val = (-M <= val && val < M) ? val : val % M;
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

    friend Mint binpow(Mint a, int b) {
        Mint ret(1);
        for (; b; b >>= 1, a *= a)
            if (b & 1)
                ret *= a;
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
    friend istream &operator>>(istream &i, Mint &m) { int x; i >> x; m.val = x; return i; }
};
//}}}

//Matrices {{{
using mat = vector<vector<Mint>>;
mat mult(mat x, mat y) {
    mat ret(C, vector<Mint>(C));
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < C; ++j)
            for (int k = 0; k < C; ++k)
                ret[i][j] += x[i][k] * y[k][j];
    return ret;
}
mat binpow(mat m, ll k) {
    mat ret(C, vector<Mint>(C));
    for (int i = 0; i < C; ++i)
        ret[i][i] = 1;
    while (k) {
        if (k & 1)
            ret = mult(ret, m);
        m = mult(m, m), k >>= 1;
    }
    return ret;
}
//}}}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; ll k;
    cin >> n >> k;
    vector<Mint> dp(C);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        ll l, r; int c;
        cin >> l >> r >> c;
        r = min(k, r);
        mat m(C, vector<Mint>(C));
        for (int i = 0; i <= c; ++i) {
            m[i][i] = 1;
            if (i - 1 >= 0)
                m[i - 1][i] = 1;
            if (i + 1 <= c)
                m[i + 1][i] = 1;
        }
        m = binpow(m, r - l);
        vector<Mint> ndp(C);
        for (int i = 0; i < C; ++i)
            for (int j = 0; j < C; ++j)
                ndp[i] += dp[j] * m[j][i];
        dp = ndp;
        if (r == k)
            break;
    }
    cout << dp[0] << '\n';
}
