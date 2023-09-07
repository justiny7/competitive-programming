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

// Lazy Segtree {{{
struct Node {
    int tot, on, lz;
    Node() {}
    Node(int _tot, int _on) {
        tot = _tot, on = _on;
        lz = 0;
    }
};
template<class T> struct LZ_ST {
    inline T comb(T a, T b) {
        T res = Node(0, 0);
        res.tot = a.tot ^ b.tot;
        res.on = a.on ^ b.on;
        return res;
    } // or whatever function

    int sz;
    vector<T> t;

    void init(vector<int> &a, string &s) {
        sz = a.size();
        t.resize(sz * 4);

        build(0, sz - 1, 1, a, s);
    }
    void build(int l, int r, int v, vector<int> &a, string s) {
        if (l == r) {
            if (s[l] == '0')
                t[v] = Node(a[l], 0);
            else
                t[v] = Node(a[l], a[l]);
        } else {
            int m = l + r >> 1;
            build(l, m, v * 2, a, s);
            build(m + 1, r, v * 2 + 1, a, s);
            t[v] = comb(t[v * 2], t[v * 2 + 1]);
        }
    }
    inline void push(int l, int r, int v) {
        if (l != r && t[v].lz) { // might have to change
            t[v * 2].on ^= t[v * 2].tot;
            t[v * 2 + 1].on ^= t[v * 2 + 1].tot;
            t[v * 2].lz ^= 1;
            t[v * 2 + 1].lz ^= 1;
        }
        t[v].lz = 0;
    }
    void upd(int ql, int qr, int l, int r, int v) {
        if (qr < l || ql > r) return;
        if (l >= ql && r <= qr) // might have to change
            t[v].on ^= t[v].tot, t[v].lz ^= 1;
        else {
            push(l, r, v);
            int m = l + r >> 1;
            upd(ql, qr, l, m, v * 2);
            upd(ql, qr, m + 1, r, v * 2 + 1);
            t[v] = comb(t[v * 2], t[v * 2 + 1]);
        }
    }
    void upd(int ql, int qr) {
        upd(ql, qr, 0, sz - 1, 1);
    }
    T query(int ql, int qr, int l, int r, int v) {
        if (qr < l || ql > r) return Node(0, 0);
        if (l >= ql && r <= qr) return t[v];
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
    int n;
    read(n);

    vector<int> a(n);
    string s;
    read(a, s);

    LZ_ST<Node> st;
    st.init(a, s);

    int q;
    read(q);
    while(q--) {
        int t;
        read(t);
        
        if (t & 1) {
            int l, r;
            read(l, r), l--, r--;
            st.upd(l, r);
        } else {
            int g;
            read(g);
            Node res = st.query(0, n - 1);
            if (g)
                write(res.on, ' ');
            else
                write(res.on ^ res.tot, ' ');
        }
    }

    print();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t; read(t);
    while (t--)
        solve();
}

