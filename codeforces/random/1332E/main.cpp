#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//{{{ Mint
const int M = 998244353;
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

ll n, m, l, r, dif;
Mint o, e;

Mint binpow(Mint a, ll b) {
    Mint ret(1);
    for (; b; b >>= 1, a *= a)
        if (b & 1)
            ret *= a;
    return ret;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> l >> r, dif = r - l;
    if ((n * m) & 1)
        cout << binpow(r - l + 1, n * m) << '\n';
    else {
        o = dif / 2 + ((dif & 1) ? 1 : (l & 1));
        e = r - l + 1 - o;
        cout << (binpow(e + o, n * m) + binpow(e - o, n * m)) / 2 << '\n';
    }
}
