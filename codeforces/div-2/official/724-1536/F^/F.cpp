#include <bits/stdc++.h>
using namespace std;

//Mint {{{
const int M = 1e9 + 7;
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

const int N = 1e6 + 69;
int n;
Mint ans, fact[N];

Mint nCr(int q, int r) {
    return fact[q] / (fact[r] * fact[q - r]);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * Mint(i);
    cin >> n;
    for (int i = (n & 1); i <= n / 2; i += 2) //i empty cells
        ans += nCr(n - i, i) * fact[n - i - 1];
    ans *= n * 2; //n spots to place first letter, can start with A or B
    cout << ans << '\n';
}
