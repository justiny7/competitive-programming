#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=3e5+1, mxV=1e6+1;
ll n, q, spf[mxV], d[mxV], a[mxN];
struct node {
    ll sum, mx;
} t[mxN<<2];

node merge(node a, node b) {
    return node{a.sum+b.sum, max(a.mx, b.mx)};
}
void build(int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v]=node{a[l], a[l]};
        return;
    }
    int m=l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}
ll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return 0;
    if (lo>=l && hi<=r)
        return t[v].sum;
    int m=lo+hi>>1;
    return query(l, r, lo, m, v<<1)+query(l, r, m+1, hi, v<<1|1);
}
void upd(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo || t[v].mx<3)
        return;
    if (lo==hi) {
        ll val=t[v].sum;
        t[v]=node{d[val], d[val]};
        return;
    }
    int m=lo+hi>>1;
    upd(l, r, lo, m, v<<1);
    upd(l, r, m+1, hi, v<<1|1);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}

int main() {
    for (int i=1; i<mxV; ++i)
        for (int j=i; j<mxV; j+=i)
            ++d[j];
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r, --l, --r;
        if (t&1)
            upd(l, r);
        else
            cout << query(l, r) << '\n';
    }
}

