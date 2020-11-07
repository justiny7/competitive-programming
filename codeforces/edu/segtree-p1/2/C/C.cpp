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
int query(int x, int l=0, int r=n-1, int v=1) {
    if (l==r)
        return l;
    int mid=(l+r)/2;
    if (seg[v*2]>=x)
        return query(x, l, mid, v*2);
    else
        return query(x, mid+1, r, v*2+1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (m--) {
        int t; cin >> t;
        if (t==1) {
            int a, b;
            cin >> a >> b;
            upd(a, b);
        }
        else {
            int x; cin >> x;
            cout << (seg[1]>=x?query(x):-1) << '\n';
        }
    }
}

