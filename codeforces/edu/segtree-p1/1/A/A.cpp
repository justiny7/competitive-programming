#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
ll n, m, a[mxN], seg[mxN*4];

void build(int v=1, int l=0, int r=n-1) {
    if (l==r) {
        seg[v]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(v*2, l, mid);
    build(v*2+1, mid+1, r);
    seg[v]=seg[v*2]+seg[v*2+1];
}

void upd(int i, ll x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        seg[v]=x;
        return;
    }
    int mid=(l+r)/2;
    if (i<=mid)
        upd(i, x, l, mid, v*2);
    else
        upd(i, x, mid+1, r, v*2+1);
    seg[v]=seg[v*2]+seg[v*2+1];
}

ll query(int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (hi<l || lo>r)
        return 0;
    if (lo>=l && hi<=r)
        return seg[v];
    int mid=(lo+hi)/2;
    return query(l, r, lo, mid, v*2)+query(l, r, mid+1, hi, v*2+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a==1)
            upd(b, c);
        else
            cout << query(b, c-1) << '\n';
    }
}

