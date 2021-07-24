#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, q;

struct ST {
    int t[N * 4];

    ST() { memset(t, 0, sizeof(t)); }

    void upd(int i, int x, int l = 1, int r = n, int v = 1) {
        if (l == r)
            t[v] = x;
        else {
            int m = l + r >> 1;
            if (i <= m)
                upd(i, x, l, m, v * 2);
            else
                upd(i, x, m + 1, r, v * 2 + 1);
            t[v] = min(t[v * 2], t[v * 2 + 1]);
        }
    }
    int query(int ql, int qr, int l = 1, int r = n, int v = 1) {
        if (ql > r || qr < l)
            return INT_MAX;
        if (l >= ql && r <= qr)
            return t[v];
        int m = l + r >> 1;
        return min(query(ql, qr, l, m, v * 2), query(ql, qr, m + 1, r, v * 2 + 1));
    }
} lf, rt;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        int x; cin >> x;
        lf.upd(i, x - i);
        rt.upd(i, x + i);
    }

    while (q--) {
        int t; cin >> t;

        if (t & 1) {
            int i, x;
            cin >> i >> x;
            lf.upd(i, x - i);
            rt.upd(i, x + i);
        }
        else {
            int i; cin >> i;
            cout << min(i + lf.query(1, i), -i + rt.query(i, n)) << '\n';
        }
    }
}
