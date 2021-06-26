#include <bits/stdc++.h>
using namespace std;

// a[i] > median --> (less/equal - greater) / 2
// a[i] <= median --> (greater/equal - less + 1) / 2

// Lazy Segree {{{
template<class T> struct LZ_ST {
    const T ID = -1e9, LZ_ID = 0; // or whatever ID
    inline T comb(T a, T b) {
        return max(a, b); // or whatever function
    }

    int sz;
    vector<T> t, lz;
    LZ_ST() {}
    LZ_ST(int _sz) { init(sz); }
    LZ_ST(vector<T> &v) { init(v); }

    void init(int _sz) {
        sz = _sz;
        t.resize(sz * 4);
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

const int N = 2e5 + 69;
int n, ans[N];
vector<int> pos[N];
LZ_ST<int> pref[2], suff[2]; // 0 --> less, 1 --> greater

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        pos[x].push_back(i);
    }

    for (int c = 0; c < 2; ++c) {
        pref[c].init(n + 1);
        suff[c].init(n + 1);
    }

    for (int i = 1; i <= n; ++i) {
        pref[0].upd(i, n, -1);
        pref[1].upd(i, n, 1);
        suff[0].upd(1, i, -1);
        suff[1].upd(1, i, 1);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j : pos[i]) {
            pref[0].upd(j, n, 2);
            suff[0].upd(1, j, 2);
        }

        for (int j : pos[i]) {
            int cur = 0;
            for (int c = 0; c < 2; ++c)
                cur = max(cur, c + max(0, pref[c].query(j, n) - pref[c].query(j, j)) + max(0, suff[c].query(1, j) - suff[c].query(j, j)));

            ans[j] = cur / 2;
        }

        for (int j : pos[i]) {
            pref[1].upd(j, n, -2);
            suff[1].upd(1, j, -2);
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " \n"[i == n];
}
