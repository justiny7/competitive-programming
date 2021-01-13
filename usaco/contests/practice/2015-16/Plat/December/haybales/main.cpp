//Yay worked first try - just lazy segtree
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
int n, q;
ll a[mxN], lz[mxN<<2];
struct node {
    ll sum, mn;
} t[mxN<<2];

inline node merge(node a, node b) {
    node ret;
    ret.sum=a.sum+b.sum;
    ret.mn=min(a.mn, b.mn);
    return ret;
}
void build(int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v].sum=t[v].mn=a[l];
        return;
    }
    int m=l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}
void push(int l, int r, int v) {
    if (l^r) {
        int m=l+r>>1;
        lz[v<<1]+=lz[v];
        lz[v<<1|1]+=lz[v];
        t[v<<1].sum+=(m-l+1)*lz[v];
        t[v<<1|1].sum+=(r-m)*lz[v];
        t[v<<1].mn+=lz[v];
        t[v<<1|1].mn+=lz[v];
    }
    lz[v]=0;
}
void upd(int l, int r, ll x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        t[v].sum+=(hi-lo+1)*x, t[v].mn+=x, lz[v]+=x;
        return;
    }
    push(lo, hi, v);
    int m=lo+hi>>1;
    upd(l, r, x, lo, m, v<<1);
    upd(l, r, x, m+1, hi, v<<1|1);
    t[v]=merge(t[v<<1], t[v<<1|1]);
}
node query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return node{0, INT_MAX};
    if (lo>=l && hi<=r)
        return t[v];
    push(lo, hi, v);
    int m=lo+hi>>1;
    return merge(query(l, r, lo, m, v<<1), query(l, r, m+1, hi, v<<1|1));
}

int main() {
    ifstream cin("haybales.in");
    ofstream cout("haybales.out");
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (q--) {
        char c; int l, r, x;
        cin >> c >> l >> r, --l, --r;
        if (c=='M')
            cout << query(l, r).mn << '\n';
        else if (c=='S')
            cout << query(l, r).sum << '\n';
        else {
            cin >> x;
            upd(l, r, x);
        }
    }
}

