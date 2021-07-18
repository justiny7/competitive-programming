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

// Lazy Segtree {{{
template<class T> struct LZ_ST {
    const T ID = INT_MAX, LZ_ID = 0; // or whatever ID
    inline T comb(T a, T b) {
        return min(a, b); // or whatever function
    }

    int sz;
    vector<T> t, lz;
    LZ_ST() {}
    LZ_ST(int _sz) { init(sz); }
    LZ_ST(vector<T> &v) { init(v); }

    void init(int _sz, bool zero = false) {
        sz = _sz;
        t.resize(sz * 4, zero ? 0 : ID);
        lz.resize(sz * 4, LZ_ID);
    }
    void init(vector<T> &a) {
        sz = a.size();
        t.resize(sz * 4);
        lz.resize(sz * 4, LZ_ID);

        build(0, sz - 1, 1, a);
    }
    void build(int l, int r, int v, vector<T> &a) {
        if (l == r)
            t[v] = a[l];
        else {
            int m = l + r >> 1;
            build(l, m, v * 2, a);
            build(m + 1, r, v * 2 + 1, a);
            t[v] = comb(t[v * 2], t[v * 2 + 1]);
        }
    }
    inline void push(int l, int r, int v) {
        if (l != r) { // might have to change
            t[v * 2] += lz[v];
            t[v * 2 + 1] += lz[v];
            lz[v * 2] += lz[v];
            lz[v * 2 + 1] += lz[v];
        }
        lz[v] = LZ_ID;
    }
    void upd(int ql, int qr, T x, int l, int r, int v) {
        //print("> ", ql, qr, x, l, r, v);
        if (qr < l || ql > r)
            return;
        if (l >= ql && r <= qr) // might have to change
            t[v] += x, lz[v] += x;
        else {
            push(l, r, v);
            int m = l + r >> 1;
            upd(ql, qr, x, l, m, v * 2);
            upd(ql, qr, x, m + 1, r, v * 2 + 1);
            t[v] = comb(t[v * 2], t[v * 2 + 1]);
        }
    }
    void upd(int ql, int qr, T x) {
        upd(ql, qr, x, 0, sz - 1, 1);
    }
    T query(int ql, int qr, int l, int r, int v) {
        //print("!", ql, qr, l, r, v);
        if (qr < l || ql > r)
            return ID;
        if (l >= ql && r <= qr)
            return t[v];

        push(l, r, v);
        int m = l + r >> 1;
        return comb(query(ql, qr, l, m, v * 2), query(ql, qr, m + 1, r, v * 2 + 1));
    }
    T query(int ql, int qr) {
        return query(ql, qr, 0, sz - 1, 1);
    }
};
// }}}

void solve() {
    int n, k;
    read(n, k);

    vector<int> ans(n, INT_MAX);
    LZ_ST<int> st;
    st.init(k, 1);

    vector<array<int, 2>> a(k);
    for (int c = 0; c < 2; ++c)
        for (int i = 0; i < k; ++i)
            read(a[i][c]);
    sort(all(a));

    for (auto &[p, x] : a)
        --p;

    for (int i = 0; i < k; ++i)
        st.upd(i, i, a[i][1] + a[i][0]);

    int p = -1;
    for (int i = 0; i < n; ++i) {
        //print(">", i, p);
        //for (int j = 0; j < k; ++j)
        //write(st.query(j, j), " \n"[j == k - 1]);

        ans[i] = st.query(0, k - 1);

        if (p + 1 < k && i == a[p + 1][0])
            ++p;

        if (p >= 0)
            st.upd(0, p, 1);
        if (p + 1 < k)
            st.upd(p + 1, k - 1, -1);
    }

    print(ans);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}
