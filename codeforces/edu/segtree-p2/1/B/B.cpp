#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, q, t[mxN<<2], lz[mxN<<2];

void push(int v, int l, int r) {
    if (l^r) {
        lz[v<<1]=max(lz[v<<1], lz[v]);
        lz[v<<1|1]=max(lz[v<<1|1], lz[v]);
    }
    else
        t[v]=max(t[v], lz[v]);
}
void upd(int l, int r, int x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    push(v, lo, hi);
    if (lo>=l && hi<=r) {
        lz[v]=max(lz[v], x);
        return;
    }
    int m=lo+hi>>1;
    upd(l, r, x, lo, m, v<<1);
    upd(l, r, x, m+1, hi, v<<1|1);
    t[v]=max(t[v<<1], t[v<<1|1]);
}
int query(int i, int l=0, int r=n-1, int v=1) {
    push(v, l, r);
    if (l==r)
        return t[v];
    int m=l+r>>1;
    if (i<=m)
        return query(i, l, m, v<<1);
    else
        return query(i, m+1, r, v<<1|1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    while (q--) {
        int a; cin >> a;
        if (a&1) {
            int l, r, v;
            cin >> l >> r >> v;
            upd(l, r-1, v);
        }
        else {
            int v; cin >> v;
            cout << query(v) << '\n';
        }
    }
}

