#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;
int n, q;
map<int, int> mp;

//{{{ PST
const int MX = 1e7 + 1;
int node = 1, rt[N], t[MX], lc[MX], rc[MX];

void dup(int &v) {
    ++node;
    lc[node] = lc[v];
    rc[node] = rc[v];
    t[node] = t[v];
    v = node;
}
void upd(int &v, int i, int x, int l = 0, int r = n - 1) {
    dup(v);
    if (l == r) {
        t[v] = x;
        return;
    }
    int m = l + r >> 1;
    if (i <= m)
        upd(lc[v], i, x, l, m);
    else
        upd(rc[v], i, x, m + 1, r);
    t[v] = t[lc[v]] + t[rc[v]];
}
int query(int v, int l, int r, int lo = 0, int hi = n - 1) {
    if (l > hi || r < lo)
        return 0;
    if (lo >= l && hi <= r)
        return t[v];
    int m = lo + hi >> 1;
    return query(lc[v], l, r, lo, m) + query(rc[v], l, r, m + 1, hi);
}
//}}}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        if (i > 0)
            rt[i] = rt[i - 1];
        int x; cin >> x;
        if (mp.count(x))
            upd(rt[i], mp[x], 0);
        upd(rt[i], mp[x] = i, 1);
    }
    while (q--) {
        int l, r;
        cin >> l >> r, --l, --r;
        cout << query(rt[r], l, r) << '\n';
    }
}
