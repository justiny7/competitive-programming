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

const int N = 2e5 + 69;
Mint fact[N];

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    sort(a.begin(), a.end());
    if (a.back() - a[a.size() - 2] > 1) {
        cout << "0\n";
        return;
    }

    map<int, int> cnt;
    for (int i : a)
        ++cnt[i];

    if (cnt.size() == 1 || cnt.rbegin()->second > 1) {
        cout << fact[n] << '\n';
        return;
    }

    auto it = cnt.rbegin();
    int q = it->first, r = next(it)->first;

    if (q - r > 1) {
        cout << fact[n] << '\n';
        return;
    }

    // order largest two
    Mint ans = fact[cnt[r]] * cnt[r];

    // place everything else
    int left = n - cnt[q] - cnt[r];
    for (int i = 1; i <= left; ++i)
        ans *= n - left + i;

    cout << ans << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = fact[i - 1] * i;

    int t;
    cin >> t;
    while (t--)
        solve();
}

