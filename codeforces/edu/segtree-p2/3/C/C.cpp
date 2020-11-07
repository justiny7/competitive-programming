#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, q, t[mxN<<2], lz[mxN<<2];

inline void push(int v, int l, int r) {
    if (l^r) {
        t[v<<1]+=lz[v];
        t[v<<1|1]+=lz[v];
        lz[v<<1]+=lz[v];
        lz[v<<1|1]+=lz[v];
    }
    lz[v]=0;
}
void upd(int l, int r, int x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        t[v]+=x, lz[v]+=x;
        return;
    }
    push(v, lo, hi);
    int m=lo+hi>>1;
    upd(l, r, x, lo, m, v<<1);
    upd(l, r, x, m+1, hi, v<<1|1);
    t[v]=max(t[v<<1], t[v<<1|1]);
}
int query(int x, int b, int l=0, int r=n-1, int v=1) {
    if (t[v]<x || r<b)
        return -1;
    if (l==r)
        return l;
    push(v, l, r);
    int m=l+r>>1, cur=query(x, b, l, m, v<<1);
    return (~cur?cur:query(x, b, m+1, r, v<<1|1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    while (q--) {
        int a; cin >> a;
        if (a==1) {
            int l, r, v;
            cin >> l >> r >> v;
            upd(l, r-1, v);
        }
        else {
            int x, l;
            cin >> x >> l;
            cout << query(x, l) << '\n';
        }
    }
}

