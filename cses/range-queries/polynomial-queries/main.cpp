#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
ll n, q, a[mxN];
struct node {
    ll x, lz=0, lz2=0;
} seg[mxN*4];

void build(int v=1, int l=0, int r=n-1) {
    if (l==r) {
        seg[v].x=a[l];
        return;
    }
    int m=(l+r)/2;
    build(v*2, l, m);
    build(v*2+1, m+1, r);
    seg[v].x=seg[v*2].x+seg[v*2+1].x;
}

void go(int v, int l, int r) {
    seg[v].lz+=seg[v/2].lz, seg[v].lz2+=seg[v/2].lz2;
    seg[v].x+=seg[v/2].lz*(r-l+1)+seg[v/2].lz2*(1LL*r*(r+1)/2-1LL*l*(l-1)/2);
}

void push(int v, int l, int r) {
    int m=(l+r)/2;
    go(v*2, l, m);
    go(v*2+1, m+1, r);
    seg[v].lz=seg[v].lz2=0;
}

void upd(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        seg[v].lz+=1-l, ++seg[v].lz2;
        seg[v].x+=1LL*(1-l)*(hi-lo+1)+1LL*hi*(hi+1)/2-1LL*lo*(lo-1)/2;
        return;
    }
    push(v, lo, hi);
    int m=(lo+hi)/2;
    upd(l, r, lo, m, v*2);
    upd(l, r, m+1, hi, v*2+1);
    seg[v].x=seg[v*2].x+seg[v*2+1].x;
}

ll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return 0;
    if (lo>=l && hi<=r)
        return seg[v].x;
    push(v, lo, hi);
    int m=(lo+hi)/2;
    return query(l, r, lo, m, v*2)+query(l, r, m+1, hi, v*2+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b, --a, --b;
        if (t==1)
            upd(a, b);
        else
            cout << query(a, b) << '\n';
    }
}

