#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
int n, q;
ll a[mxN];
struct node {
    ll sum, mx, ind;
} t[mxN<<2];

node merge(node x, node y) {
    node ret;
    ret.sum=x.sum+y.sum;
    ret.mx=max(x.mx, y.mx);
    ret.ind=(x.mx>y.mx)?x.ind:y.ind;
    return ret;
}
void build(int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v]=node{a[l], a[l], l};
        return;
    }
    int m=l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}
void upd(int i, ll x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v]=node{x, x, i};
        return;
    }
    int m=l+r>>1;
    if (i<=m)
        upd(i, x, l, m, v<<1);
    else
        upd(i, x, m+1, r, v<<1|1);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}
node query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return node{0, -1, -1};
    if (lo>=l && hi<=r)
        return t[v];
    int m=lo+hi>>1;
    return merge(query(l, r, lo, m, v<<1), query(l, r, m+1, hi, v<<1|1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (q--) {
        int t, l, r, x; cin >> t;
        if (t==1) {
            cin >> l >> r, --l, --r;
            cout << query(l, r).sum << '\n';
        }
        else if (t==2) {
            cin >> l >> r >> x, --l, --r;
            node c=query(l, r);
            while (c.mx>=x) {
                upd(c.ind, c.mx%x);
                c=query(l, r);
            }
        }
        else {
            cin >> l >> x, --l;
            upd(l, x);
        }
    }
}

