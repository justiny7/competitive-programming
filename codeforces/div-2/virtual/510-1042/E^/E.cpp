#include <bits/stdc++.h>
using namespace std;

// Modular Int {{{
template<int MD> struct mi {
    int v;
    explicit operator int() const { return v; }
    mi(long long _v = 0) {
        v = (-MD <= _v && _v < MD) ? _v : _v % MD;
        if (v < 0) v += MD;
    }

    mi &operator+=(const mi &o) { if ((v += o.v) >= MD) v -= MD; return *this; }
    mi &operator-=(const mi &o) { if ((v -= o.v) < 0) v += MD; return *this; }
    mi &operator*=(const mi &o) { v = 1LL * v * o.v % MD; return *this; }
    mi &operator/=(const mi &o) { return (*this) *= inv(o); }

    friend mi operator+(mi a, const mi &b) { return a += b; }
    friend mi operator-(mi a, const mi &b) { return a -= b; }
    friend mi operator*(mi a, const mi &b) { return a *= b; }
    friend mi operator/(mi a, const mi &b) { return a /= b; }

    friend mi inv(const mi &m) { return binpow(m, MD - 2); }
    friend mi binpow(mi b, long long e) {
        mi ret = 1;
        for (; e; e >>= 1, b *= b) if (e & 1) ret *= b;
        return ret;
    }

    friend bool operator==(const mi &a, const mi &b) { return a.v == b.v; }
    friend bool operator!=(const mi &a, const mi &b) { return !(a == b); }
    friend bool operator<(const mi &a, const mi &b) { return a.v < b.v; }

    friend istream &operator>>(istream &i, mi &m) { long long x; i >> x; m.v = x; return i; }
    friend ostream &operator<<(ostream &o, const mi &m) { o << m.v; return o; }
};
// }}}

const int MOD = 998'244'353;
using Mint = mi<MOD>;

const int N = 1e3 + 69;
int n, m;
Mint ev[N][N];

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m;

    map<int, vector<array<int, 2>>> mp;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            mp[x].push_back({i, j});
        }
    }

    Mint s_ev, s_r, s_c, s_rsq, s_csq, cur;
    for (auto [x, v] : mp) {
        if (cur.v > 0) {
            for (auto [r, c] : v) {
                ev[r][c] += s_ev;
                ev[r][c] += s_rsq;
                ev[r][c] += s_csq;
                ev[r][c] -= s_r * r * 2;
                ev[r][c] -= s_c * c * 2;
                ev[r][c] /= cur;
                ev[r][c] += r * r;
                ev[r][c] += c * c;
            }
        }

        for (auto [r, c] : v) {
            s_ev += ev[r][c];
            s_r += r;
            s_c += c;
            s_rsq += r * r;
            s_csq += c * c;
        }

        cur += v.size();
    }

    int xr, xc;
    cin >> xr >> xc;
    cout << ev[xr - 1][xc - 1] << '\n';
}

