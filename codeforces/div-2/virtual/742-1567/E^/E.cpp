#include <bits/stdc++.h>
using namespace std;

using ll = long long;

inline ll calc(ll x) {
    return x * (x + 1) / 2;
}

const int N = 2e5 + 69;
int n, q, a[N];

struct node {
    int lf, rt;
    ll pref, suff, ans;
    bool all;
} t[N * 4];

node ID() {
    node ret;
    ret.lf = INT_MAX;
    ret.rt = INT_MIN;
    ret.pref = ret.suff = ret.ans = 0;
    ret.all = 0;
    return ret;
}
node merge(node l, node r) {
    node ret;
    ret.lf = l.lf;
    ret.rt = r.rt;

    if (l.rt > r.lf) {
        ret.pref = l.pref;
        ret.suff = r.suff;
        ret.ans = l.ans + r.ans;
        ret.all = 0;
    } else {
        if (l.all && r.all) {
            ll here = l.pref + r.pref;
            ret.pref = ret.suff = here;
            ret.ans = calc(here);
            ret.all = 1;
        } else if (l.all) {
            ret.pref = l.pref + r.pref;
            ret.suff = r.suff;
            ret.ans = l.ans + r.ans - calc(l.pref) - calc(r.pref) + calc(l.pref + r.pref);
            ret.all = 0;
        } else if (r.all) {
            ret.pref = l.pref;
            ret.suff = l.suff + r.suff;
            ret.ans = l.ans + r.ans - calc(l.suff) - calc(r.suff) + calc(l.suff + r.suff);
            ret.all = 0;
        } else {
            ret.pref = l.pref;
            ret.suff = r.suff;
            ret.ans = l.ans + r.ans - calc(l.suff) - calc(r.pref) + calc(l.suff + r.pref);
            ret.all = 0;
        }
    }

    // cout << l.lf << " " << r.rt << " " << ret.ans << '\n';

    return ret;
}
void upd(int i, int x, int l = 1, int r = n, int v = 1) {
    if (l == r) {
        t[v].lf = t[v].rt = x;
        t[v].pref = t[v].suff = t[v].ans = 1;
        t[v].all = 1;
    } else {
        int m = l + r >> 1;
        if (i <= m)
            upd(i, x, l, m, v * 2);
        else
            upd(i, x, m + 1, r, v * 2 + 1);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }
}
node query(int ql, int qr, int l = 1, int r = n, int v = 1) {
    if (l > qr || r < ql)
        return ID();
    if (l >= ql && r <= qr)
        return t[v];
    int m = l + r >> 1;
    return merge(query(ql, qr, l, m, v * 2), query(ql, qr, m + 1, r, v * 2 + 1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        upd(i, a[i]);
    }

    while (q--) {
        int t;
        cin >> t;

        if (t & 1) {
            int x, v;
            cin >> x >> v;

            upd(x, v);
        } else {
            int l, r;
            cin >> l >> r;

            cout << query(l, r).ans << '\n';
        }
    }
}

