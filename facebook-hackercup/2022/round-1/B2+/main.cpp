#include <bits/stdc++.h>
using namespace std;

/*
1
5
2 3
0 0
0 2
3 3
0 3
6
0 0
3 1
2 1
1 0
2 0
0 3

answer: 219
*/

using ll = long long;

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

Mint get(map<ll, Mint> &mp, vector<ll> &v) {
    Mint res = 0, cur = 0;
    Mint abv = 0, bel = 0;
    Mint add = 0, sub = 0;

    multiset<ll> ms;
    for (ll i : v) {
        mp[i];
        ms.insert(i);

        abv += 1;
        cur += Mint(i * i);

        if (i)
            sub += Mint(i * i) - Mint((i - 1) * (i - 1));
    }

    // cout << "start: " << cur << " " << sub << '\n';

    ll lst = 0, n = v.size();
    for (auto [x, c] : mp) {
        Mint dif = x - lst;
        // cout << "> " << dif << " " << bel << " " << abv << '\n';
        cur += add * dif;
        cur -= sub * dif;

        cur += Mint(dif * (dif - 1)) * Mint(n);

        add += dif * bel * 2;
        sub -= dif * abv * 2;

        res += cur * c;

        while (ms.size() && *ms.begin() == x) {
            abv -= 1;
            bel += 1;
            add += 1;
            if (x != 0)
                sub += 1;
            ms.erase(ms.begin());
        }

        lst = x;

        // cout << x << " " << cur << " " << add << " " << sub << " " << bel << " " << abv << '\n';
    }

    // cout << "sub: " << sub << '\n';
    assert(sub == 0);

    return res;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i] >> b[i];

    map<ll, Mint> mp_x, mp_y;

    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        mp_x[x] += 1, mp_y[y] += 1;
    }

    Mint res = 0;
    res += get(mp_x, a);
    res += get(mp_y, b);

    cout << res << '\n';
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case #" << tc << ": ";
        solve();
    }
}

