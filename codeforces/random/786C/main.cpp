#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int n, a[N], lst[N];

//{{{ PST
const int L = 40;
int node = 1, rt[N], t[N * L], lc[N * L], rc[N * L];

void dup(int &v) {
    ++node;
    lc[node] = lc[v];
    rc[node] = rc[v];
    t[node] = t[v];
    v = node;
}
void upd(int &v, int i, int x, int l = 1, int r = n) {
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
int query(int v, int l, int r, int lo = 1, int hi = n) {
    if (l > hi || r < lo)
        return 0;
    if (lo >= l && hi <= r)
        return t[v];
    int m = lo + hi >> 1;
    return query(lc[v], l, r, lo, m) + query(rc[v], l, r, m + 1, hi);
}
int get(int v, int k, int l = 1, int r = n) {
    if (l == r)
        return l;
    int m = l + r >> 1;
    if (t[rc[v]] <= k)
        return get(lc[v], k - t[rc[v]], l, m);
    else
        return get(rc[v], k, m + 1, r);
}
//}}}

int main() {
    memset(lst, -1, sizeof(lst));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        rt[i] = rt[i - 1];
        if (~lst[a[i]])
            upd(rt[i], lst[a[i]], 0);
        upd(rt[i], lst[a[i]] = i, 1);
    }
    for (int t = 1; t <= n; ++t) {
        int ans = 0, cur = n;
        while (cur >= 1) {
            ++ans;
            int nxt = get(rt[cur], t);
            if (nxt == 1 && query(rt[cur], 1, cur) <= t)
                break;
            cur = nxt;
        }
        cout << ans << " \n"[t == n];
    }
}
