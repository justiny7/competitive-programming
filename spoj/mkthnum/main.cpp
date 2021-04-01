#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;
int n, m, a[N], cmp[N];
map<int, int> mp;

//{{{ PST
const int SZ = 1e7 + 420;
int node = 1, rt[N], t[SZ], lc[SZ], rc[SZ];

void dup(int &v) {
    ++node;
    lc[node] = lc[v];
    rc[node] = rc[v];
    t[node] = t[v];
    v = node;
}
void upd(int &v, int i, int l = 0, int r = n - 1) {
    dup(v);
    if (l == r) {
        ++t[v];
        return;
    }
    int m = l + r >> 1;
    if (i <= m)
        upd(lc[v], i, l, m);
    else
        upd(rc[v], i, m + 1, r);
    t[v] = t[lc[v]] + t[rc[v]];
}
int query(int vl, int vr, int k, int lo = 0, int hi = n - 1) {
    if (lo == hi)
        return lo;
    int m = lo + hi >> 1, cnt = t[lc[vr]] - t[lc[vl]];
    if (cnt < k)
        return query(rc[vl], rc[vr], k - cnt, m + 1, hi);
    else
        return query(lc[vl], lc[vr], k, lo, m);
}
//}}}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i], cmp[i] = a[i];
    sort(cmp, cmp + n);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(cmp, cmp + n, a[i]) - cmp;
        mp[pos] = a[i];
        if (i > 0)
            rt[i] = rt[i - 1];
        upd(rt[i], pos);
    }
    while (m--) {
        int l, r, k;
        cin >> l >> r >> k, --l, --r;
        cout << mp[query((l > 0 ? rt[l - 1] : 0), rt[r], k)] << '\n';
    }
}
