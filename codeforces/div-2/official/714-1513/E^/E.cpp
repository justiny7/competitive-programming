#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

const int N = 1e5 + 69;
int n;
ll x, a[N];
Mint ans, fact[N];
map<int, int> freq;

int main() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i;
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i], x += a[i];
        ++freq[a[i]];
    }
    if (x % n) {
        cout << "0\n";
        return 0;
    }
    x /= n;
    int ovr = 0, und = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > x)
            ++ovr;
        else if (a[i] < x)
            ++und;
    }
    if (ovr <= 1 || und <= 1) {
        ans = fact[n];
        for (auto [p, c] : freq)
            ans /= fact[c];
    }
    else {
        Mint c_ovr = fact[ovr], c_und = fact[und], rest = fact[n];
        for (auto [p, c] : freq) {
            if (p < x)
                c_und /= fact[c];
            else if (p > x)
                c_ovr /= fact[c];
        }
        rest /= fact[ovr + und];
        rest /= fact[n - ovr - und];
        ans = 2 * c_ovr * c_und * rest;
        //cout << c_ovr << " " << c_und << " " << rest << '\n';
    }
    cout << ans << '\n';
}
