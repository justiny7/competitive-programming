#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, q, t[mxN<<2];
bool lz[mxN<<2];

inline void push(int v, int l, int r) {
    if (!lz[v])
        return;
    if (l^r) {
        int m=l+r>>1;
        lz[v<<1]^=1, lz[v<<1|1]^=1;
        t[v<<1]=(m-l+1)-t[v<<1];
        t[v<<1|1]=(r-m)-t[v<<1|1];
    }
    lz[v]=0;
}
void upd(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        t[v]=(hi-lo+1)-t[v], lz[v]^=1;
        return;
    }
    push(v, lo, hi);
    int m=lo+hi>>1;
    upd(l, r, lo, m, v<<1);
    upd(l, r, m+1, hi, v<<1|1);
    t[v]=t[v<<1]+t[v<<1|1];
}
int query(int k, int l=0, int r=n-1, int v=1) {
    if (r==l)
        return l;
    push(v, l, r);
    int m=l+r>>1;
    if (t[v<<1]>k)
        return query(k, l, m, v<<1);
    else
        return query(k-t[v<<1], m+1, r, v<<1|1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    while (q--) {
        int a; cin >> a;
        if (a==1) {
            int l, r;
            cin >> l >> r;
            upd(l, r-1);
        }
        else {
            int k; cin >> k;
            cout << query(k) << '\n';
        }
    }
}

