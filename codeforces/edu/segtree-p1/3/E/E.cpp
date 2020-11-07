#include <bits/stdc++.h>
using namespace std;
using ll=long long;

const int mxN=1e5+1;
ll n, q, seg[mxN*4];

void upd(int x, int l, int r, int lo=0, int hi=n-1, int v=1) {
    if (l>hi || r<lo)
        return;
    if (lo>=l && hi<=r) {
        seg[v]+=x;
        return;
    }
    int m=lo+hi>>1;
    upd(x, l, r, lo, m, v<<1);
    upd(x, l, r, m+1, hi, v<<1|1);
}
ll query(int i, int l=0, int r=n-1, int v=1) {
    if (l==r)
        return seg[v];
    int m=l+r>>1;
    if (i<=m)
        return seg[v]+query(i, l, m, v<<1);
    else
        return seg[v]+query(i, m+1, r, v<<1|1);
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    while (q--) {
        int t; cin >> t;
        if (t==1) {
            int a, b, c;
            cin >> a >> b >> c;
            upd(c, a, b-1);
        }
        else {
            int v; cin >> v;
            cout << query(v) << '\n';
        }
    }
}

