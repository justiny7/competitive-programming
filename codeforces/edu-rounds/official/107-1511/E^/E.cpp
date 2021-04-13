#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//{{{ Mint
const ll M = 998'244'353;
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

const int N = 3e5 + 69;
int n, m, tot;
string s[N], orig[N];
Mint ans, o[N][2], dp[N], p[N];

/*
 * Counting pairs:
 * o[i][0] = # of 0's + # of paired 1's on row i
 * o[i][1] = # of unpaired 1's on row i
 *
 * Each unpaired 1 adds one 0 (append 0) and one paired 1 (add 1)
 * Each paired 1 and 0 adds one 0 (append 0)
 * So o[i][0] = o[i - 1][0] + o[i - 1][1] * 2
 *
 * Each paired 1 and 0 adds one unpaired 1 (append 1)
 * So o[i][1] = o[i - 1][0]
 *
 * Counting dominoes:
 * dp[i] = # of dominoes created over all ways to paint i rows
 *
 * Each domino already created contributes twice to the next row (append 0/1)
 * Each unpaired 1 creates o[i][1] new dominoes (append 1)
 * So dp[i] = dp[i - 1] * 2 + o[i - 1][1]
*/

int main() {
    p[0] = 1;
    for (int i = 1; i < N; ++i)
        p[i] = p[i - 1] * Mint(2);
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        tot += count(s[i].begin(), s[i].end(), 'o');
    }
    for (int t = 0; t < 2; ++t) {
        for (int i = 0; i < n; ++i) {
            //cout << "row " << i  << '\n';
            int c = 0; bool f = 1;
            for (int j = 1; j <= m; ++j) {
                if (s[i][j - 1] == '*') {
                    ans += dp[j - 1] * p[tot - c];
                    f = 1, c = 0;
                }
                else {
                    ++c;
                    if (f) {
                        f = 0;
                        o[j][0] = o[j][1] = 1;
                    }
                    else {
                        o[j][0] = o[j - 1][0] + o[j - 1][1] * 2;
                        o[j][1] = o[j - 1][0];
                        dp[j] = dp[j - 1] * 2 + o[j - 1][1];
                    }
                }
                //cout << j << " " << dp[j] << " " << o[j][0] << " " << o[j][1] << '\n';
            }
            ans += dp[m] * p[tot - c];
            for (int i = 0; i <= m; ++i) {
                dp[i] = 0;
                for (int j = 0; j < 2; ++j)
                    o[i][j] = 0;
            }
        }
        for (int i = 0; i < n; ++i)
            orig[i] = s[i];
        for (int i = 0; i < m; ++i) {
            s[i] = string(n, '$');
            for (int j = 0; j < n; ++j)
                s[i][j] = orig[j][i];
        }
        swap(n, m);
    }
    cout << ans << '\n';
}
