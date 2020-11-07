#include <bits/stdc++.h>
using namespace std;

const int mxN=1e5+1;
int n, m, a[mxN], seg[mxN*4];

void build(int v=1, int l=0, int r=n-1) {
    if (l==r) {
        seg[v]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(v*2, l, mid);
    build(v*2+1, mid+1, r);
    seg[v]=max(seg[v*2], seg[v*2+1]);
}
void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        seg[v]=x;
        return;
    }
    int mid=(l+r)/2;
    if (i<=mid)
        upd(i, x, l, mid, v*2);
    else
        upd(i, x, mid+1, r, v*2+1);
    seg[v]=max(seg[v*2], seg[v*2+1]);
}
int query(int x, int b, int l=0, int r=n-1, int v=1) {
    if (seg[v]<x || r<b)
        return -1;
    if (l==r)
        return l;
    int mid=(l+r)/2, cur=query(x, b, l, mid, v*2);
    if (~cur)
        return cur;
    else
        return query(x, b, mid+1, r, v*2+1);
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
            cout << query(b, c) << '\n';
    }
}

