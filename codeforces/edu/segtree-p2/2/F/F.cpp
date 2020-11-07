#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
int n, q;
ll t[mxN<<2], lz[mxN<<2];

inline void push(int v, int l, int r) {
    if (lz[v]<0)
        return;
    if (l^r) {
        int m=l+r>>1;
        lz[v<<1]=lz[v<<1|1]=lz[v];
        t[v<<1]=1LL*(m-l+1)*lz[v];
        t[v<<1|1]=1LL*(r-m)*lz[v];
    }
    lz[v]=-1;
}
void upd(int l, int r, ll x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        t[v]=1LL*(hi-lo+1)*x, lz[v]=x;
        return;
    }
    push(v, lo, hi);
    int m=lo+hi>>1;
    upd(l, r, x, lo, m, v<<1);
    upd(l, r, x, m+1, hi, v<<1|1);
    t[v]=t[v<<1]+t[v<<1|1];
}
ll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return 0;
    if (lo>=l && hi<=r)
        return t[v];
    push(v, lo, hi);
    int m=lo+hi>>1;
    return query(l, r, lo, m, v<<1)+query(l, r, m+1, hi, v<<1|1);
}

int main() {
    memset(lz, -1, sizeof(lz));
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    while (q--) {
        int a, l, r, v;
        cin >> a >> l >> r;
        if (a==1) {
            cin >> v;
            upd(l, r-1, v);
        }
        else
            cout << query(l, r-1) << '\n';
    }
}

