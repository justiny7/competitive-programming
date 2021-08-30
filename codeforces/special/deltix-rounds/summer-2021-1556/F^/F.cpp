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

const int MOD = 1e9 + 7;
using Mint = mi<MOD>;

const int N = 14;
int n, a[N];
Mint prob[N][N], win[N][1 << N], all[1 << N];

// Code stolen from vkgainz orz
// win[i][msk] = probability of i beating everyone in msk
// all[msk] = probability of everyone in msk forming exactly one SCC

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j)
                prob[i][j] = Mint(a[i]) / Mint(a[i] + a[j]);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            win[i][j] = 1;
            for (int k = 0; k < n; ++k)
                if (j & (1 << k))
                    win[i][j] *= prob[i][k];
        }
    }

    for (int i = 0; i < (1 << n); ++i) {
        for (int s = i; s; s = (s - 1) & i) {
            if (s == i)
                all[i] = 1; // base case
            else {
                // for each subset of the mask, subtract probability of everyone inside
                // the subset beating everyone outside the subset but still in the mask
                Mint sub = 1;
                for (int j = 0; j < n; ++j)
                    if (s & (1 << j))
                        sub *= win[j][s ^ i];

                all[i] -= all[s] * sub;
            }
        }
    }

    Mint ans;
    for (int i = 0; i < n; ++i) {
        // contribution of each element
        Mint here;
        for (int j = 0; j < (1 << n); ++j) {
            if (!(j & (1 << i)))
                continue;

            // iterate over winning configurations that contain i
            vector<int> in, out;
            for (int k = 0; k < n; ++k) {
                if (j & (1 << k))
                    in.push_back(k);
                else
                    out.push_back(k);
            }

            // draw edges from everything inside winning config to outside
            Mint btwn = 1;
            for (int s : in)
                for (int t : out)
                    btwn *= prob[s][t];

            // probability of reaching this state * weight of 1 (only considering contribution of element i)
            here += all[j] * btwn;
        }

        ans += here;
    }

    cout << ans << '\n';
}

