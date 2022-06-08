#include <bits/stdc++.h>
using namespace std;

// Lazy Segtree {{{
template<class T> struct LZ_ST_MIN {
    static constexpr T ID = INT_MAX, LZ_ID = -1; // or whatever ID
    inline T comb(T a, T b) { return min(a, b); } // or whatever function

    int sz;
    vector<T> t, lz;

    void init(int _sz, T val = ID) {
        sz = _sz;
        t.assign(sz * 4, val);
        lz.assign(sz * 4, LZ_ID);
    }
    void init(vector<T> &a) {
        sz = a.size();
        t.resize(sz * 4);
        lz.assign(sz * 4, LZ_ID);

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
        if (l != r && lz[v] != LZ_ID) { // might have to change
            int m = l + r >> 1;
            t[v * 2] = lz[v];
            t[v * 2 + 1] = lz[v];
            lz[v * 2] = lz[v];
            lz[v * 2 + 1] = lz[v];
        }
        lz[v] = LZ_ID;
    }
    void upd(int ql, int qr, T x, int l, int r, int v) {
        if (qr < l || ql > r) return;
        if (l >= ql && r <= qr) // might have to change
            t[v] = lz[v] = x;
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
        if (qr < l || ql > r) return ID;
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

// Lazy Segtree {{{
template<class T> struct LZ_ST_SUM {
    static constexpr T ID = 0, LZ_ID = -1; // or whatever ID
    inline T comb(T a, T b) { return a + b; } // or whatever function

    int sz;
    vector<T> t, lz;

    void init(int _sz, T val = ID) {
        sz = _sz;
        t.assign(sz * 4, val);
        lz.assign(sz * 4, LZ_ID);
    }
    void init(vector<T> &a) {
        sz = a.size();
        t.resize(sz * 4);
        lz.assign(sz * 4, LZ_ID);

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
        if (l != r && lz[v] != LZ_ID) { // might have to change
            int m = l + r >> 1;
            t[v * 2] = lz[v] * (m - l + 1);
            t[v * 2 + 1] = lz[v] * (r - m);
            lz[v * 2] = lz[v];
            lz[v * 2 + 1] = lz[v];
        }
        lz[v] = LZ_ID;
    }
    void upd(int ql, int qr, T x, int l, int r, int v) {
        if (qr < l || ql > r) return;
        if (l >= ql && r <= qr) // might have to change
            t[v] = x * (r - l + 1), lz[v] = x;
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
        if (qr < l || ql > r) return ID;
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
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int &i : a)
        cin >> i;

    vector<int> pref(a);
    for (int i = 1; i < n; ++i)
        pref[i] = min(pref[i], pref[i - 1]);

    LZ_ST_MIN<int> mn;
    LZ_ST_SUM<int> sm;

    mn.init(pref);
    sm.init(n + 69);

    for (int i = 0; i < n; ++i)
        if (i == 0 || pref[i] != pref[i - 1])
            sm.upd(i, i, 1);

    // for (int i = 0; i < n; ++i)
        // cout << mn.query(i, i) << " ";
    // cout << '\n';

    while (m--) {
        int ind, d;
        cin >> ind >> d, --ind;

        a[ind] -= d;

        if (a[ind] < mn.query(ind, ind)) {
            int l = ind, r = n - 1, best = -1;
            while (l <= r) {
                int mid = l + r >> 1;

                if (mn.query(mid, mid) >= a[ind])
                    best = mid, l = mid + 1;
                else
                    r = mid - 1;
            }

            // cout << ">" << best << " ";

            if (~best) {
                mn.upd(ind, best, a[ind]);
                sm.upd(ind, ind, 1);
                sm.upd(ind + 1, best, 0);
            }
        }

        cout << sm.query(0, n - 1) << " ";
    }

    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();
}

