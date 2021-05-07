#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int n, q, t[N * 4], lz[N * 4];

void push(int l, int r, int v) {
    if (l != r) {
        t[v << 1] = max(t[v << 1], lz[v]);
        t[v << 1 | 1] = max(t[v << 1 | 1], lz[v]);
        lz[v << 1] = max(lz[v << 1], lz[v]);
        lz[v << 1 | 1] = max(lz[v << 1 | 1], lz[v]);
    }
    lz[v] = 0;
    //cout << "> " << l << " " << r << " " << lz[v] << '\n';
}
void upd(int ql, int qr, int x, bool f, int l = 0, int r = n - 1, int v = 1) {
    if (ql > r || qr < l)
        return;
    if (l >= ql && r <= qr) {
        if (f)
            t[v] = lz[v] = x;
        else {
            t[v] = max(t[v], x);
            lz[v] = max(lz[v], x);
        }
        return;
    }
    push(l, r, v);
    int m = l + r >> 1;
    upd(ql, qr, x, f, l, m, v << 1);
    upd(ql, qr, x, f, m + 1, r, v << 1 | 1);
}
int get(int i, int l = 0, int r = n - 1, int v = 1) {
    push(l, r, v);
    if (l == r)
        return t[v];
    int m = l + r >> 1;
    if (i <= m)
        return get(i, l, m, v << 1);
    else
        return get(i, m + 1, r, v << 1 | 1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        upd(i, i, x, 1);
    }
    cin >> q;
    while (q--) {
        int t; cin >> t;
        if (t & 1) {
            int i, x;
            cin >> i >> x, --i;
            upd(i, i, x, 1);
        }
        else {
            int x; cin >> x;
            upd(0, n - 1, x, 0);
        }
    }
    for (int i = 0; i < n; ++i)
        cout << get(i) << " \n"[i == n - 1];
}
