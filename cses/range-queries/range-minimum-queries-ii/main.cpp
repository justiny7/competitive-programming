#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=2e5+1;
int n, q;
ll a[mxN], seg[mxN*4];

void build(int v=1, int l=0, int r=n-1) {
    if (l==r)
        seg[v]=a[l];
    else {
        int mid=(l+r)/2;
        build(v*2, l, mid);
        build(v*2+1, mid+1, r);
        seg[v]=min(seg[v*2], seg[v*2+1]);
    }
}

ll get(int l, int r, int li=0, int ri=n-1, int v=1) {
    if (l>r)
        return LLONG_MAX;
    if (li==l && ri==r)
        return seg[v];
    int mid=(li+ri)/2;
    return min(get(l, min(r, mid), li, mid, v*2), get(max(l, mid+1), r, mid+1, ri, v*2+1));
}

void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r)
        seg[v]=x;
    else {
        int mid=(l+r)/2;
        if (i<=mid)
            upd(i, x, l, mid, v*2);
        else
            upd(i, x, mid+1, r, v*2+1);
        seg[v]=min(seg[v*2], seg[v*2+1]);
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (q--) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t==1)
            upd(a-1, b);
        else
            cout << get(a-1, b-1) << '\n';
    }
}

