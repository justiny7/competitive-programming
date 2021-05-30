#include <bits/stdc++.h>
using namespace std;

const int K = 3e5 + 69;
int n, m, k, cmp[K];
array<int, 3> segs[K];

//PST {{{
const int SZ = 2e7 + 69;
int node = 1, rt[K], t[SZ], lc[SZ], rc[SZ];

void rep(int &v) {
    ++node;
    lc[node] = lc[v];
    rc[node] = rc[v];
    t[node] = t[v];
    v = node;
}
void upd(int &v, int i, int x, int l = 0, int r = n - 1) {
    rep(v);
    if (l == r) {
        if (x == 1e9)
            t[v] = x;
        else
            t[v] = min(t[v], x);
        return;
    }
    int m = l + r >> 1;
    if (i <= m)
        upd(lc[v], i, x, l, m);
    else
        upd(rc[v], i, x, m + 1, r);
    t[v] = max(t[lc[v]], t[rc[v]]);
}
int query(int v, int ql, int qr, int l = 0, int r = n - 1) {
    if (ql > r || qr < l)
        return 0;
    if (l >= ql && r <= qr)
        return t[v];
    int m = l + r >> 1;
    return max(query(lc[v], ql, qr, l, m), query(rc[v], ql, qr, m + 1, r));
}
//}}}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < 3; ++j)
            cin >> segs[i][j];
        cmp[i] = segs[i][0];
        --segs[i][2];
    }
    sort(segs, segs + k);
    sort(cmp, cmp + k);
    for (int i = 0; i < n; ++i)
        upd(rt[k], i, 1e9);
    for (int i = k - 1; ~i; --i) {
        rt[i] = rt[i + 1];
        upd(rt[i], segs[i][2], segs[i][1]);
    }
    while (m--) {
        int l, r, x, y, ret;
        cin >> l >> r >> x >> y, --l, --r;
        ret = lower_bound(cmp, cmp + k, x) - cmp;
        if (ret >= k)
            cout << "no";
        else
            cout << (query(rt[ret], l, r) > y ? "no" : "yes");
        cout << endl;
    }
}
