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
        seg[v]=0;
    }
}

void upd(int x, int l, int r, int li=0, int ri=n-1, int v=1) {
    assert(r<n); assert(l>=0); assert(l<n); assert(r>=0);
    if (l>r)
        return;
    if (l==li && r==ri)
        seg[v]+=x;
    else {
        int mid=(li+ri)/2;
        upd(x, l, min(r, mid), li, mid, v*2);
        upd(x, max(l, mid+1), r, mid+1, ri, v*2+1);
    }
}

ll get(int i, int l=0, int r=n-1, int v=1) {
    if (l==r)
        return seg[v];
    int mid=(l+r)/2;
    if (i<=mid)
        return seg[v]+get(i, l, mid, v*2);
    else
        return seg[v]+get(i, mid+1, r, v*2+1);
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    while (q--) {
        int t; cin >> t;
        if (t==1) {
            int a, b, c;
            cin >> a >> b >> c, --a, --b;
            upd(c, a, b);
        }
        else {
            int k; cin >> k, --k;
            cout << get(k) << '\n';
        }
    }
}
