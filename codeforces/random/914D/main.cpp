#include <bits/stdc++.h>
using namespace std;

const int mxN=5e5+1;
int n, q, a[mxN], t[mxN<<2];

void build(int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v]=a[l];
        return;
    }
    int m=l+r>>1;
    build(l, m, v<<1);
    build(m+1, r, v<<1|1);
    t[v]=__gcd(t[v<<1], t[v<<1|1]);
}
void upd(int i, int x, int l=0, int r=n-1, int v=1) {
    if (l==r) {
        t[v]=x;
        return;
    }
    int m=l+r>>1;
    if (i<=m)
        upd(i, x, l, m, v<<1);
    else
        upd(i, x, m+1, r, v<<1|1);
    t[v]=__gcd(t[v<<1], t[v<<1|1]);
}
int query(int l, int r, int x, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return 0;
    if (lo>=l && hi<=r) {
        if (t[v]%x==0)
            return 0;
        while (lo<hi) {
            if (t[v<<1]%x && t[v<<1|1]%x)
                return 2;
            int m=lo+hi>>1;
            if (t[v<<1]%x)
                v<<=1, hi=m;
            else
                (v<<=1)|=1, lo=m+1;
        }
        return 1;
    }
    int m=lo+hi>>1;
    return (query(l, r, x, lo, m, v<<1)+query(l, r, x, m+1, hi, v<<1|1));
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0; i<n; ++i)
        cin >> a[i];
    build();
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t&1) {
            int l, r, x, best;
            cin >> l >> r >> x;
            cout << (query(l-1, r-1, x)>1?"NO":"YES") << '\n';
        }
        else {
            int i, x;
            cin >> i >> x;
            upd(i-1, x);
        }
    }
}

