#include <bits/stdc++.h>
using namespace std;

// Mint {{{
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
// }}}

// Matrices {{{
using Mat = vector<vector<Mint>>;

Mat make_mat(int SZ) {
    return Mat(SZ, vector<Mint>(SZ));
}
Mat operator*(const Mat &a, const Mat &b) {
    int SZ = a.size();
    Mat ret = make_mat(SZ);
    for (int i = 0; i < SZ; ++i)
        for (int j = 0; j < SZ; ++j)
            for (int k = 0; k < SZ; ++k)
                ret[i][j] += a[i][k] * b[k][j];
    return ret;
}
Mat binpow(Mat b, long long e) {
    int SZ = b.size();
    Mat ret = make_mat(SZ);
    for (int i = 0; i < SZ; ++i)
        ret[i][i] = 1;
    for (; e; b = b * b, e >>= 1)
        if (e & 1)
            ret = ret * b;
    return ret;
}
// }}}

const int N = 169;
int n, k, z, o, p, a[N];
Mat m = make_mat(N);

#define C2(x) (x * (x - 1) / 2)

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        o += a[i]; // o = # of 1's
        z += 1 - a[i]; // z = # of 0's
    }

    for (int i = 0; i < z; ++i) // p = # of 0's on prefix of z
        p += 1 - a[i];

    for (int i = 0; i <= z; ++i) {
        int l0 = i, r0 = z - l0,
            l1 = z - i, r1 = o - l1;

        m[i][i] = C2(o) + C2(z) + l0 * r0 + l1 * r1; // choose 0's on same side, 1's on same side, 0's on opposite side, 1's on opposite side
        if (i > 0)
            m[i][i - 1] = l0 * r1; // choose 0 on left, 1 on right
        if (i < z)
            m[i][i + 1] = l1 * r0; // choose 1 on left, 0 on right
    }

    Mat ret = binpow(m, k);

    Mint tot;
    for (int i = 0; i <= z; ++i)
        tot += ret[p][i];

    cout << Mint(ret[p][z] / tot) << '\n';
}
