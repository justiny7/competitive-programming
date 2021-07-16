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
template<class T> bool ckmin(T &a, const T b) { return (b < a) ? a = b, 1 : 0; }
template<class T> bool ckmax(T &a, const T b) { return (a < b) ? a = b, 1 : 0; }

using ll = long long;

// }}}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Segtree {{{
template<class T> struct ST {
    const T ID = -1; //or whatever ID
    inline T comb(T a, T b) {
        return max(a, b); //or whatever function
    }
    inline void app(T &v, T x) {
        v = x; //or whatever assignment
    }

    int sz;
    vector<T> t;

    ST() {}

    void init(int _sz) {
        t.resize(sz << 1, ID);
    }
    void init(vector<T> &v) {
        sz = v.size();
        t.resize(sz << 1);
        for (int i = 0; i < sz; ++i)
            t[i + sz] = v[i];
        for (int i = sz - 1; i; --i)
            t[i] = comb(t[i << 1], t[i << 1 | 1]);
    }
    void upd(int i, T x) {
        for (app(t[i += sz], x); i > 1; i >>= 1)
            t[i >> 1] = comb(t[i], t[i ^ 1]);
    }
    T query(int l, int r) {
        T ret_l = ID, ret_r = ID;
        for (l += sz, r += sz + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1)
                ret_l = comb(ret_l, t[l++]);
            if (r & 1)
                ret_r = comb(ret_r, t[--r]);
        }
        return comb(ret_l, ret_r);
    }
};
// }}}

bool ok(vector<int> &v) {
    if (v.size() < 3)
        return 1;

    int n = v.size();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            for (int k = j + 1; k < n; ++k)
                if (v[i] <= v[j] && v[j] <= v[k] ||
                    v[i] >= v[j] && v[j] >= v[k])
                    return 0;

    return 1;
}

void solve() {
    int n;
    read(n);

    vector<int> a(n);
    read(a);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = i;
        vector<int> cur;
        while (j < n) {
            cur.push_back(a[j]);

            if (!ok(cur))
                break;

            ++j;
        }

        //print(">", i, j);
        ans += j - i;
    }

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
