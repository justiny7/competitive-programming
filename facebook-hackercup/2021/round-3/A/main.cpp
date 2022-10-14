#include <bits/stdc++.h>
using namespace std;

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

// DSU {{{
struct DSU {
    vector<int> dsu, p;
    void init(int n) {
        dsu.assign(n, -1);
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    
    int find(int v) {
        return dsu[v] < 0 ? v : dsu[v] = find(dsu[v]);
    }
    int par(int v) {
        return p[find(v)];
    }
    int size(int v) {
        return -dsu[find(v)];
    }
    bool merge(int u, int v) {
        if ((u = find(u)) == (v = find(v)))
            return 0;
        if (dsu[u] < dsu[v])
            swap(u, v);
        p[u] = p[v] = min(p[u], p[v]);
        dsu[v] += dsu[u], dsu[u] = v;
        return 1;
    }
    bool same_set(int u, int v) {
        return find(u) == find(v);
    }
};
// }}}

void solve() {
    ll n, m;
    cin >> n >> m;

    Mint cur = n * (n - 1) / 2, ans = 1;
    vector<char> vis(n + 1);

    DSU d;
    d.init(n + 1);

    while (m--) {
        int u, v;
        cin >> u >> v;

        if (u > v)
            swap(u, v);

        ll tot = 0;
        Mint sub;
        for (int i = v; i >= u; i = d.par(i) - 1) {
            ll sz = d.size(i);
            sub += tot * sz;
            sub += sz * (sz - 1);
            tot += sz;
            // cout << "! " << i << " " << sz << '\n';
        }

        // cout << "> " << tot << " " << sub << '\n';

        cur += Mint(tot * (tot - 1)) - sub;
        // cout << cur << '\n';
        ans *= cur;

        for (int i = v, nxt = d.par(i) - 1; nxt >= u; i = nxt, nxt = d.par(i) - 1)
            d.merge(i, nxt);
    }
    
    cout << ans << '\n';
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

