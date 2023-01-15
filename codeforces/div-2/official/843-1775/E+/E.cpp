#include <bits/stdc++.h>
using namespace std;

// TEMPLATE {{{

/* Macros */
#define all(x) (x).begin(), (x).end()
#define finish(...) return void(print(__VA_ARGS__))

/* Input */
template<class T> void read(T &x) { cin >> x; }
template<class H, class T> void read(pair<H, T> &p) { cin >> p.first >> p.second; }
template<class T, size_t S> void read(array<T, S> &a) { for (T &i : a) read(i); }
template<class T> void read(vector<T> &v) { for (T &i : v) read(i); }

template<class H, class... T> void read(H &h, T &...t) { read(h); read(t...); }

/* Output */
template<class H, class T> ostream &operator<<(ostream &o, pair<H, T> &p) { o << p.first << " " << p.second; return o; }
template<class T, size_t S> ostream &operator<<(ostream &o, array<T, S> &a) { string s; for (T i : a) o << s << i, s = " "; return o; }
template<class T> ostream &operator<<(ostream &o, vector<T> &v) { string s; for (T i : v) o << s << i, s = " "; return o; }

template<class T> void write(T x) { cout << x; }
template<class H, class... T> void write(const H &h, const T &...t) { write(h); write(t...); }

void print() { write('\n'); }
template<class H, class... T> void print(const H &h, const T &...t) { write(h); if (sizeof...(t)) write(' '); print(t...); }

/* Misc */
bool ckmin(auto &a, const auto &b) { return (a > b) ? a = b, 1 : 0; }
bool ckmax(auto &a, const auto &b) { return (a < b) ? a = b, 1 : 0; }

using ll = long long;

// }}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Segtree {{{
template<class T> struct ST {
    static constexpr T ID = pair<ll, ll>{INT_MAX, INT_MAX}; // or whatever ID
    inline T comb(T a, T b) { return min(a, b); } // or whatever function

    int sz;
    vector<T> t;

    void init(int _sz, T val = ID) {
        t.assign((sz = _sz) << 1, ID);
    }
    void init(vector<T> &v) {
        t.resize((sz = v.size()) << 1);
        for (int i = 0; i < sz; ++i)
            t[i + sz] = v[i];
        for (int i = sz - 1; i; --i)
            t[i] = comb(t[i << 1], t[i << 1 | 1]);
    }
    void upd(int i, T x) {
        for (t[i += sz] = x; i > 1; i >>= 1)
            t[i >> 1] = comb(t[i], t[i ^ 1]);
    }
    T query(int l, int r) {
        T ql = ID, qr = ID;
        for (l += sz, r += sz + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ql = comb(ql, t[l++]);
            if (r & 1) qr = comb(t[--r], qr);
        }
        return comb(ql, qr);
    }
};
// }}}

void solve() {
    int n;
    read(n);

    vector<ll> a(n);
    read(a);

    vector<ll> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0)
            continue;

        if (b.empty())
            b.push_back(a[i]);
        else if ((a[i] < 0) == (b.back() < 0))
            b.back() += a[i];
        else
            b.push_back(a[i]);
    }

    int sz = b.size();

    set<pair<ll, ll>> mn, vals;
    for (int i = 0; i < sz; ++i) {
        mn.insert({abs(b[i]), i});
        vals.insert({i, abs(b[i])});
    }

    ll res = 0;
    while (mn.size()) {
        auto [v, i] = *mn.begin();
        mn.erase(mn.begin());

        res += v - res;

        /*
        print("v, i", v, i);
        for (auto p : vals)
            print("!", p);
        print();
        */

        auto it = vals.find({i, v});
        ll add = 0;
        bool f = 1;
        if (next(it) != vals.end()) {
            auto nxt = next(it);
            add += nxt->second;
            mn.erase(make_pair(nxt->second, nxt->first));
            vals.erase(nxt);
        } else {
            f = 0;
        }

        if (it != vals.begin()) {
            auto prv = prev(it);
            add += prv->second;
            mn.erase(make_pair(prv->second, prv->first));
            vals.erase(prv);
        } else {
            f = 0;
        }

        // print("add", add);

        vals.erase(it);
        if (add > 0) {
            mn.insert({add - (f ? res : 0), i});
            vals.insert({i, add - (f ? res : 0)});
        }
    }

    print(res);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

